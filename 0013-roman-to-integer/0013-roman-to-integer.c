int romanToInt(char* s) {
    // use switch statement (more efficient then if else statement)
    
    // initialize sum and length of string
    int sum = 0;

    // iterate through input Roman numerals
    for (int i = 0; s[i] != '\0'; i++){
        // case I
        switch (s[i]){
            case 'I':
                // sum += 1;
                sum += (s[i+1] == 'V' || s[i+1] == 'X') ? -1 : 1;
                break;
            case 'V':
                sum += 5;
                break;
            case 'X':
                // sum += 10;
                sum += (s[i+1] == 'L' || s[i+1] == 'C') ? -10 : 10;
                break;
            case 'L':
                sum += 50;
                break;
            case 'C':
                // sum += 100;
                sum += (s[i+1] == 'D' || s[i+1] == 'M') ? -100 : 100;
                break;
            case 'D':
                sum += 500;
                break;
            case 'M':
                sum += 1000;
                break;
        }
    }
    return sum;
}