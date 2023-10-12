bool isAnagram(char *s, char *t){
    // Step 1: check length, if the strings are equal
    int len_s = strlen(s);
    int len_t = strlen(t);
    if (len_s != len_t) return false;

    // Step 2: count each character in s and t
    int count_s[26] = {0};
    int count_t[26] = {0};
    for (int i = 0; i < len_s; i++){
        // s[i] - 'a' is the index of the character in the array
        count_s[s[i] - 'a']++;
        count_t[t[i] - 'a']++;
    }

    // Step 3: compare the count of each character
    for(int i = 0; i < 26; i++){
        if (count_s[i] != count_t[i]) return false;
    }

    // Step 4: return true if all the characters are the same
    return true;
}
