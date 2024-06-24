int countElements(int* arr, int arrSize) {
    // using array to store the count of each element
    int count = 0;
    int* hash = (int*)calloc(2000, sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        hash[arr[i]]++;
    }
    for (int i = 0; i < arrSize; i++) {
        if (hash[arr[i] + 1] > 0) {
            count++;
        }
    }
    free(hash);
    return count;
}