bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    // calculate total 2d matrix size
    int col = *matrixColSize; // dereference the column size
    int matrix_size = matrixSize * (col);
    printf("%d", matrix_size);
    
    // initialize left, right, middle index
    int left = 0;
    int right = matrix_size - 1;
    int mid = 0;

    // initialize middle index's value of 2d array
    int mid_2d_val = 0;

    // binary search
    while (left <= right){
        // calculate mid index
        mid = left + (right - left) / 2;
        
        // get middle index's value in the 2d array, which treat 2d array as 1d array
        mid_2d_val = matrix[mid/col][mid%col];

        // if target equal to mid_2d_val, return true
        if (target == mid_2d_val) return true;
        // else if target smaller than mid_2d_val, search left
        else if (target < mid_2d_val) right = mid - 1;
        // else search right
        else left = mid + 1;

    }
    return false;
}