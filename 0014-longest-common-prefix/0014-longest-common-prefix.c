// cmp function for qsort
int cmp(const void* a, const void* b){
    return strcmp(*(char**)a, *(char**)b);
}

char* longestCommonPrefix(char** strs, int strsSize) {
    // empty case
    if (strsSize == 0) return "";
    
    // sort the strings, so we can easily compare the first and last string
    qsort(strs, strsSize, sizeof(char*), cmp);
    
    // get the first and last string
    char* first = strs[0];
    char* last = strs[strsSize - 1];
    
    // initialize the result 
    char* result = (char*)malloc(sizeof(char) * 1000);
    int resultSize = 0;
    
    // compare the first and last string
    for (int i = 0; i < strlen(first); i++){
        if (first[i] == last[i]) {
            result[resultSize++] = first[i];
        } else {
            break;
        }
    }
    result[resultSize] = '\0';
    return result;
}