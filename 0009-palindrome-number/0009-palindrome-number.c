bool isPalindrome(int x) {
    // <Simple apporach>:
    // // negative case, return false
    // if (x < 0) return false;

    // // initialize reversed number & temp for extracting operation
    // int64_t reversed = 0;
    // int64_t temp = x;

    // // reverse the input number
    // while (temp != 0){
    //     // use modulo operation to extract the last digit of number
    //     int digit = temp % 10;
    //     // most important operation: multiply current reversed number by 10, and add extracted digit to it
    //     reversed = reversed * 10 + digit;
    //     // shift/remove last digit of temp numberby /10
    //     temp /= 10;
    // }

    // // compare reversed number with x, if equal return true
    // if (reversed == x) return true;
    // // return false if not equal
    // else return false;

    // <reverse half of the number (reduced time complexity and memory)>:
    // negative case, or remainder value equal to 0, ex: 10 % 10 = 0 -> but they are not palindrome
    if ((x < 0) || (x != 0 && x % 10 == 0)) return false;
    // initialize reversed value
    int64_t reversed = 0;

    // reverse half of the number
    while (x > reversed){
        // update reverse value
        reversed = (reversed * 10) + (x % 10);
        // shift/remove last digit of x number
        x /= 10;
    }

    // use "Boolean Expression Direct Return"
    return ((x == reversed) || (x == reversed / 10));
}