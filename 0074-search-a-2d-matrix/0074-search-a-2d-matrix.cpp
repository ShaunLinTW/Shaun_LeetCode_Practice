class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // get size of the 2d matrix
        int row = matrix.size();
        int col = matrix[0].size();
        int matrix_size = row*col;
        
        // initialize left, right, mid index
        int left = 0;
        int right = matrix_size - 1;
        int mid = 0;
        
        // initialize middle value of 2d array
        int mid_2d_val = 0;

        // empty case
        if (matrix.size() == 0){
            return false;
        }

        // binary search
        while (left <= right){
            // calculate mid index
            mid = left + (right - left) / 2;
            
            // most important: calculate middle index's value of 2d array, which treat 2d array as 1d array
            mid_2d_val = matrix[mid/col][mid%col];
            
            // if found target, return true
            if (target == mid_2d_val) return true;
            // if else found target smaller than mid_2d_val, search left
            else if (target < mid_2d_val) right = mid - 1;
            // else search right
            else left = mid + 1;
        }

        return false;
    }
};