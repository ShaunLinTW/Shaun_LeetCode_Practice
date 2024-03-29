class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            // count the number of elements smaller/ equal than middle element
            int c = 0;
            for(const int& el: nums)
                if(el <= mid)
                    ++c;
            
            if(c > mid)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};