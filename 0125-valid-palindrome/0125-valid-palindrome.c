bool isPalindrome(char* s) {
    char *first = s;
    char *last = s + strlen(s) - 1;

    // iterate through the string from both ends
    while (first <= last) {
        // skip non-alphanumeric characters
        if (!isalnum(*first)) {
            first++;
        } else if (!isalnum(*last)) {
            last--;
        } else {
            // compare the characters
            if (tolower(*first) != tolower(*last)) {
                return false;
            }
            first++;
            last--;
        }
    }
    return true;   
}