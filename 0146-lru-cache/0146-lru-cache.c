

// define the Node structure
typedef struct Node{
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
}Node;

// define the LRUCache structure
typedef struct {
    int capacity;
    int size;
    Node* head; // MRU
    Node* tail; // LRU
    Node** table; // Hash table for faster lookup
} LRUCache;

// create a new node
Node* createNode (int key, int value){
    // allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    // set the key and value to the new node
    newNode->key = key;
    newNode->value = value;
    // set the prev and next pointers to NULL
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}


LRUCache* lRUCacheCreate(int capacity) {
    // allocate memory for the LRUCache
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    // set the capacity of the cache
    cache->capacity = capacity;
    cache->size = 0;
    // set the head and tail to NULL
    cache->head = NULL;
    cache->tail = NULL;

    // allocate memory for the hash table
    cache->table = (Node**)malloc(sizeof(Node*)*capacity);
    // set all the pointers in the hash table to NULL
    for (int i = 0; i < capacity; i++){
        cache->table[i] = NULL;
    }

    return cache;
}

// helper function hashKey to get the index of the key in the hash table
int hashKey (int key, int capacity){
    return key % capacity;
}

// helper function moveToHead to move the node to the head of the list
void moveToHead (LRUCache* cache, Node* node){
    // if head equals to node, return
    if (cache->head == node) return;
    
    if (node->prev != NULL) node->prev->next = node->next;
    if (node->next != NULL) node->next->prev = node->prev;

    // if the node is the tail, update the tail to the previous node
    if (cache->tail == node) cache->tail = node->prev;

    node->prev = NULL;
    node->next = cache->head;
    if (cache->head != NULL) cache->head->prev = node;
    cache->head = node;

    if (cache->tail == NULL) cache->tail = node;
}

// helper function addToHead to add the node to the head of the list
void addToHead (LRUCache* cache, Node* node){
    node->next = cache->head;
    node->prev = NULL;
    if (cache->head != NULL) cache->head->prev = node;
    cache->head = node;

    if (cache->tail == NULL) {
        cache->tail = node;
    }

    cache->size++;
}

// helper function removeNode to remove the node from the list
void removeNode (LRUCache* cache, Node* node){
    if (node->prev != NULL) node->prev->next = node->next;
    else cache->head = node->next;

    if (node->next != NULL) node->next->prev = node->prev;
    else cache->tail = node->prev;

    cache->size--;
}

int lRUCacheGet(LRUCache* obj, int key) {
    // get the index of the key in the hash table
    int index = hashKey(key, obj->capacity);
    // get the node from the hash table
    Node* node = obj->table[index];

    // if the node is not NULL and the key is not the same as the key we are looking for
    while (node != NULL && node->key != key){
        node = node->next;
    }

    // if the node is NULL, return -1
    if (node == NULL) return -1;

    // move the node to the head of the list
    moveToHead(obj, node);

    return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    // get the index of the key in the hash table
    int index = hashKey(key, obj->capacity);
    // get the node from the hash table
    Node* node = obj->table[index];

    // if the node is not NULL and the key is not the same as the key we are looking for
    while (node != NULL && node->key != key){
        node = node->next;
    }

    // if the node is NULL, create a new node
    if (node == NULL){
        Node* newNode = createNode(key, value);
        // if the size of the cache is equal to the capacity, remove the tail node
        if (obj->size == obj->capacity){
            // remove the tail node, which is remove LRU from cache and hash table
            obj->table[hashKey(obj->tail->key, obj->capacity)] = NULL;
            removeNode(obj, obj->tail);
            free(obj->tail);
        }
        obj->table[index] = newNode; // add the new node to the hash table
        // add the new node to the head of the list
        addToHead(obj, newNode);
    }
    else{
        // update the value of the node
        node->value = value;
        // move the node to the head of the list
        moveToHead(obj, node);
    }
}

void lRUCacheFree(LRUCache* obj) {
    // get the head node
    Node* node = obj->head;
    // free all the nodes in the list
    while (node != NULL){
        Node* temp = node;
        node = node->next;
        free(temp);
    }
    // free the hash table
    free(obj->table);
    // free the LRUCache
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/