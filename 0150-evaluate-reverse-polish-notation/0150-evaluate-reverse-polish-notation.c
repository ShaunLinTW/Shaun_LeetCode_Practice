// stack with linked list
typedef struct Node{
    int val;
    struct Node* next;
} Node;

typedef struct Stack{
    Node* head;
} Stack;

// create a new stack
Stack* createStack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

// push
void push(Stack* stack, int val){
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = stack->head;
    stack->head = node;
}

// pop
int pop(Stack* stack){
    if (stack->head == NULL) return -1;
    Node* node = stack->head;
    stack->head = stack->head->next;
    int val = node->val;
    free(node);
    return val;
}

// top
int top(Stack* stack){
    if (stack->head == NULL) return -1;
    return stack->head->val;
}

// is empty
bool isEmpty(Stack* stack){
    return stack->head == NULL;
}

int evalRPN(char** tokens, int tokensSize) {
    // create a stack to store tokens
    Stack* S = createStack();
    // iterate through tokens
    for (int i = 0; i < tokensSize; i++){
        // check if token is only one character long
        if (strlen(tokens[i]) == 1 && (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/')){
            int num2 = pop(S);
            int num1 = pop(S);
            switch (tokens[i][0]){
                case '+': push(S, num1 + num2); break;
                case '-': push(S, num1 - num2); break;
                case '*': push(S, num1 * num2); break;
                case '/': push(S, num1 / num2); break;
            }
        }
        else push(S, atoi(tokens[i]));
    }
    return top(S);
}