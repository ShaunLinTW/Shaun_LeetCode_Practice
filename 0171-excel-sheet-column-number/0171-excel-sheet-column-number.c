int titleToNumber(char* columnTitle) {
    int result = 0;
    for (int i = 0; i < strlen(columnTitle); i++){
        result *= 26;
        result += columnTitle[i] - 'A' + 1;
    }
    return result;
}