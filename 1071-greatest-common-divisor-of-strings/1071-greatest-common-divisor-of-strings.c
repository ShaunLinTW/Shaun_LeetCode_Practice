char* gcdOfStrings(char* str1, char* str2) {
    // Get the length of str1 and str2
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If len1 is shorter than len2, swap them to make sure len1 is always greater than or equal to len2
    if (len1 < len2) {
        char* temp = str1;
        str1 = str2;
        str2 = temp;
        int tempLen = len1;
        len1 = len2;
        len2 = tempLen;
    }

    // Direct match
    if (strcmp(str1, str2) == 0) {
        // Return a copy of str1 to avoid returning a local pointer
        char* result = (char*)malloc(strlen(str1) + 1);
        strcpy(result, str1);
        return result;
    }

    // If the first character does not match, there is no common divisor
    if (str1[0] != str2[0]) return "";

    // Check if str1 starts with str2
    if (strncmp(str1, str2, len2) == 0) {
        // Recursively check the remaining part of str1
        return gcdOfStrings(str1 + len2, str2);
        /* 
        For example (case 2):
        Initially, str1 looks like this in memory (with each character followed by its index):
        A B A B A B
        0 1 2 3 4 5
        After moving 4 characters ahead (str1 + 4), the pointer points to the substring starting from index 4:
        A B
        4 5

        so next recursive will be gcdOfStrings("AB", "ABAB");
        */
    } else {
        // If str1 does not start with str2, there is no common divisor
        return "";
    }
}