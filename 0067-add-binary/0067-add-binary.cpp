class Solution {
public:
    string addBinary(string a, string b) {
        // initialize
        string result = "";
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        
        // iterate through a and b
        while (i >= 0 || j >= 0 || carry == 1) {
            // add a[i] and b[j] to carry
            if (i >= 0) {
                carry += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                carry += b[j] - '0';
                j--;
            }
            
            // append carry % 2 to result
            result += carry % 2 + '0';
            // reset carry
            carry /= 2;
        }
        // reverse result
        reverse(begin(result), end(result));
        return result;
    }
};