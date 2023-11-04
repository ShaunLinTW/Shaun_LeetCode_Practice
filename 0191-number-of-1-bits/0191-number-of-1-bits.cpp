class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        // iterate until all bits are zero
        while (n != 0){
            count += n & 1; // apply bitwise AND with 1 to get the last bit
            n >>= 1; // Shift the bits to the right by 1.
        }
        return count;
    }
}