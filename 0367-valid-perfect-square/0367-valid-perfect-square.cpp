class Solution {
public:
    bool isPerfectSquare(int num) {
        /* binary search solution */
        // initialize start and end value
        int start = 0;
        int end = num;

        while(start <= end){
            long long mid = start + (end - start) / 2;

            if(mid * mid == num) return true;
            else if(mid * mid > num) end = mid - 1; // update end value
            else start = mid + 1; // update start value
        }
        return false;
    }
};