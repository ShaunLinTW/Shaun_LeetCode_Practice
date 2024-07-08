char* reverseWords(char* s) {
    // initialize length of the string s, and a result string
    int len = strlen(s);
    char * result = (char *)malloc(sizeof(char)*(len + 1));
    // initialize index j for result's string
    int j = 0;
    // iterate through the string, start from the end of the string
    for (int i = len - 1; i >= 0; i--){
        // skip all encountered space
        while (i >= 0 && s[i] == ' ') i--;

        // initialize index end for current visited word
        int end = i;
        while (i >= 0 && s[i] != ' ') i--; // find the start of the word

        // initialize index start for current visited word
        int start = i + 1;
        // copy current visited word to result string
        while (start <= end){
            // result[j++] = s[start++];
            result[j] = s[start];
            start++;
            j++;
        }

        // add a space to result string after copied current word
        if (i >= 0){
            // result[j++] = ' ';
            result[j] = ' ';
            j++;
        }
    }

    // if there exist extra space in the end of the result string, remove it
    if (j > 0 && result[j - 1] == ' ') j--;

    result[j] = '\0'; // assign null-terminate to the result string

    return result;
}