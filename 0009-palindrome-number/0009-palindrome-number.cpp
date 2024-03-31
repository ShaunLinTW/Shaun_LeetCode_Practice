class Solution {
public:
    bool isPalindrome(int x) {
        // negative case, or remainder value equal to 0
        if ((x < 0) || (x != 0 && x % 10 == 0)) return false;

        // initialize reverse number with range -2^31 <= x <= 2^31 - 1
        int64_t reversed = 0;
        // reverse half of the number
        while (x > reversed){
            // update reversed number
            reversed = (reversed * 10) + (x % 10);
            // shift/remove the last digit of x number
            x /= 10;
        }

        // use "Boolean Expression Direct Return", rightside condition is handling cases where x is an odd-length palindrome
        return ((x == reversed) || (x == reversed / 10));
    }
};