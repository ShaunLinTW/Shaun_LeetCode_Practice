bool isSubsequence(char* s, char* t) {
    // special case, if s is empty, return true, because empty could be any subsequence of t
    if (strlen(s) == 0){
        return true;
    }
    
    // initialize index j to track current position in string s
    int j = 0;

    // iterate through string t
    for (int i = 0; i < strlen(t); i++){
        // if index s[j] == t[i], increment index j to the next position of string s
        if (s[j] == t[i]){
            j++;
        }
    }
    // if index j reach the end of the string s, means find all the match, return true
    if (j == strlen(s)){
        return true;
    }
    return false;
}