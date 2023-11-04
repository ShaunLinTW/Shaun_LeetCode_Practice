uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;

    for (int i = 0; i < 32; i++){
        result <<= 1; // each time move left 1 bit
        result |= n & 1; // get the last bit of n byt doing AND operation with 1 and then OR with result
        n >>= 1; // move right 1 bit
    }
    return result;
}