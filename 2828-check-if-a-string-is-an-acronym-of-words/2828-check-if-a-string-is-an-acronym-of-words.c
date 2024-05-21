bool isAcronym(char ** words, int wordsSize, char * s){
    // initialize a acronym string
    char * str = (char *)malloc(sizeof(char) * 1000);
    str[0] = '\0';
    for(int i = 0; i < wordsSize; i++) strncat(str, &words[i][0], 1);
    return (strcmp(str, s) == 0);
}
