class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for (int i = 0; i < 32; i++) {
            result <<= 1; // doing this first to make room for the next bit
            result |= n & 1; // add the last bit of n to result by doing an OR
            n >>= 1; // shift n to the right by 1
        }
        //n = 00000000000000000000000000000001
        //                                   i
        //r = 1

        //n = 00000000000000000000000000000001
        //                                  i
        //r = 10
        // .
        // .
        // .
        //n = 00000000000000000000000000000001
        //    i  
        //r = 10000000000000000000000000000000
        
        return result;
    }
};