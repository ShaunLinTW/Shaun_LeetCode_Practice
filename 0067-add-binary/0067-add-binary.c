char* addBinary(char* a, char* b) {
    // initialize
    int sizeA = strlen(a);
    int sizeB = strlen(b);
    int sizeCarry = (sizeA > sizeB ? sizeA : sizeB) +1; // +1 for carry
    char *c = (char *)malloc(sizeof(char) * (sizeCarry+1)); // +1 for '\0'
    int carry = 0;
    c[sizeCarry] = '\0';

    // iterate from the end of the string
    while (sizeA > 0 || sizeB > 0 || carry == 1) {
        // update carry
        if (sizeA > 0) {
            carry += a[sizeA-1] - '0';
            sizeA--; // move to the left
        }
        if (sizeB > 0) {
            carry += b[sizeB-1] - '0';
            sizeB--; // move to the left
        }
        // update result
        c[sizeCarry-1] = carry % 2 + '0';
        carry /= 2; // reset carry
        sizeCarry--; // move to the left
    }
    return c + sizeCarry;
}