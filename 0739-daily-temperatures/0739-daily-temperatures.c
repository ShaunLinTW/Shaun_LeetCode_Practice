/*
Monotonoic Stack approach:
We should maintain the top element of the stack is bigger than the new element.
Also, element in the bottom of the stack should possess a larger value. (creating a monotonically decreasing stack)
The top element of the stack cannot be smaller than the element to be pushed into the stack, and if it is smaller, remove/pop the top element.
(Note that since we need index information to calculate each answer, I store indexes in the stack.)
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    
}

// # include <stdlib.h>
// # include <stdio.h>

// int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
//     int * ret = calloc(temperaturesSize, sizeof(int));
//     *returnSize = temperaturesSize;
//     int * stk = calloc(temperaturesSize, sizeof(int)); // store indexes
//     int pt = -1; // stack pointer (point to the top element, '-1' represent the stack is currently empty)
    
//     // starting from the end of the array
//     for (int i = temperaturesSize-1; i >= 0; i--){
//         while(pt != -1 && temperatures[i] >= temperatures[stk[pt]]) pt--; // pop
//         ret[i] = (pt == -1? 0: stk[pt]-i);
//         stk[++pt] = i; // push index to stack
//     }
//     free(stk);
//     return ret;
// }

// int main(){
//     int temperatures[] = {73, 74, 75, 71, 69, 72, 76, 73};
//     int temperaturesSize = 8;
//     int returnSize;
//     int * result = dailyTemperatures(temperatures, temperaturesSize, &returnSize);
//     for (int i = 0; i < returnSize; i++){
//         printf("%d ", result[i]);
//     }
//     free(result);
//     return 0;
// }