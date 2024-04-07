/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// define hashtable struct
struct hashtable
{
    int value;
    int cnt;
};

// helper function for qsort
int cmp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

// helper function for hashtable qsort
int cmph(const void *a, const void *b)
{
    return ((struct hashtable *)b)->cnt - ((struct hashtable *)a)->cnt;
}

int* topKFrequent(int* nums, int size, int k, int* returnSize) {
    // edge case
    if(k == 0 || size == 0){
        *returnSize = k;
        return 0;
    }
    // edge case, if size is less than k, return 0
    if (size < k){
        *returnSize = 0;
        return 0;
    }
    // edge case, if size is equal to k and k is 1, return nums
    if(size == k && k == 1){
        *returnSize = 1;
        return nums;    
    }
    
    int *results = calloc(k, sizeof(int)); // allocate memory for results, use calloc to initialize to 0
    // create hashtable
    struct hashtable hash[size];
    memset(hash,0,sizeof(struct hashtable)*size); // initialize hashtable to 0
    int i;
    int count=1; // count for hashtable
    *returnSize = k; // return size is k

    // sort nums array
    qsort(nums, size,sizeof(int),cmp);
    
    hash[0].value=nums[0]; // initialize first value
    hash[0].cnt++; // increment count
    
    // iterate through nums array and populate hashtable
    for (i=1;i<size;i++){
        // if the current value is the same as the previous value, increment count
        if(hash[count-1].value == nums[i]){
            hash[count-1].cnt++;
        } 
        // if the current value is different from the previous value, increment count and populate hashtable
        else {
            count++;
            hash[count-1].value = nums[i];
            hash[count-1].cnt++;
        }
    }
    
    // sort hashtable
    qsort(hash, count,sizeof(hash[0]),cmph);
    
    // populate results array
    for(i=0;i<k;i++){
        results[i] = hash[i].value;
    }
    
    return results;
    
}