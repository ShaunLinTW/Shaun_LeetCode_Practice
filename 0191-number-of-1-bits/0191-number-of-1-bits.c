int hammingWeight(uint32_t n) {
    // initialize counter
    int counter = 0;

    // iterate until all bits are zero
    while (n != 0){
        counter += n & 1; // apply bitwise AND with 1 to get the last bit 
        n >>= 1; // shift the bits to the right by 1
    }
    return counter;
}