/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    // initialize
    *returnSize = n + 1;
    int *ans = (int *)malloc(sizeof(int) * (*returnSize));
    ans[0] = 0;

    // iterate from 1 to n+1
    for (int i = 1; i < (*returnSize); i++) {
        int count = 0;
        int num = i; // copy i to num
        while (num) { // count the number of 1 in num
            count += num & 1; // if the last bit is 1, count++
            num >>= 1; // shift right
        }
        ans[i] = count; // store the count to ans[i]
    }
    return ans;
}