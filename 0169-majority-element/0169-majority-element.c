int majorityElement(int* nums, int numsSize) {
    // in C language, default library don't have unordered_map or sor algorithm
    // Moore Volting Algorithm approach
    // initialize count and candidate
    int count = 0;
    int candidate = 0;

    // iterate through the array
    for (int i = 0; i < numsSize; i++){
        // if count is 0, which means all candidates are same count or not start volting yet,
        // therefore, assign the current element as new candidate and increment by 1
        if (count == 0) {
            candidate = nums[i];
            count++;
        }
        // if current element same as candidate, which means it got one volt, then increment count by 1
        else if(nums[i] == candidate){
            count++;
        }
        else{
            count--;
        }
    }
    return candidate; // return most voting candidate, which is the Majority Element, this could be work for not even n/2 case
}