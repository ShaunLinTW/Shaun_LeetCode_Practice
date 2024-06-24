int strStr(char* haystack, char* needle) {
    // empty case 
    if(needle[0] == '\0') return 0;
    // two pointers method, initialize pointer i, j and length of haystack and needle
    int i = 0;
    int j = 0;
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    while(i < haystack_len && j < needle_len){
        if (haystack[i] == needle[j]){
            // increase two pointer if the string element match
            i++;
            j++;
            // if the whole pattern has been matched, then return the value by going needle size steps backwards from the current index in array
            if (j == needle_len) return i - needle_len;
        }
        // when no match, start checking from the haystack index
        else{
            i = i - j + 1; // goes backwards till whatever length has been matched, which means only update 1st pointer
            j = 0;// check from pattern's beginning, which means restart 2nd pointer
        }
    }
    return -1;
}