bool isPerfectSquare(int num) {
    /* binary search solution */
    int start = 0; 
    int end = num;

    while(start <= end){
        // update mid value
        long long mid = start + (end - start) / 2;
        
        if(mid * mid == num) return true;
        else if(mid * mid > num) end = mid - 1;
        else start = mid + 1;
    }
    return false;
}