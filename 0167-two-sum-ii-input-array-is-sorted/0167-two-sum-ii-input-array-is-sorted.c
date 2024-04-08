/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    // set return size to 2
    *returnSize = 2;
    // initialize result array using pointer
    int* result = (int*)malloc(sizeof(int) * (*returnSize));
    // initialize two pointers
    int j = 0;
    int k = numbersSize - 1;

    // iterate through array until index j meet k
    while (j < k){
        // calculate sum of the two indices
        int sum = numbers[j] + numbers[k];

        // if sum equal to target, update result's array
        if (sum == target){
            // note that: return index start from 1 & C array don't have append operation, so just start from result array' index 0
            result[0] = j + 1;
            result[1] = k + 1;
            return result;
        }
        // if sum greater then target, move index k to left
        else if (sum > target){
            k--;
        }
        // if sum less then target, move index j to right
        else {
            j++;
        }
    }
    return result;
}