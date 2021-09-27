/*
 * Convert to a string, reverse it, then convert back to integer.
 */
/*
int reverse(int x) {
    if (x == std::numeric_limits<int>::min()) {
        return 0;
    }
    
    int sign = 1;
    
    if (x < 0 ) {
        sign = -1;
        x = -x;
    }
    
    std::string x_str = std::to_string(x);
    std::cout << x_str << "\n";
    std::reverse(x_str.begin(), x_str.end());
    
    int result = 0;
    try {
        result = std::stoi(x_str);
    } catch (const std::out_of_range& err) {
        return 0;
    }
    
    return sign*result;
}
*/

/*
 * Using modulus operator to get each digit.
 * O(n) time complexity, where n = number of digits
 */
int reverse(int x) {
    if (x == std::numeric_limits<int>::min()) {
        // special case, can't be negated
        // -(-2147483648) = 2147483648 > INT_MAX
        return 0;
    }
    const int MAX = std::numeric_limits<int>::max();
    int sign = 1;
    if (x < 0) {
        sign = -1;
        x = -x;
    }
    
    /*
     * MAX = 2147483647
     * can overflow when:
     * x_rev =  214748364 * 10 + (>7), i.e. x_rev = MAX/10 && rem > 7
     * x_rev = (>=214748365) * 10 + rem, i.e. x_rev >= (MAX/10)+1
    */
    int x_rev = 0;
    int rem = 0;
    while (x != 0) {
        rem = x % 10;
        if ( (x_rev == MAX/10 && rem > 7) || (x_rev >= (MAX/10)+1) ) {
            return 0;
        }
        x_rev = x_rev * 10 + rem;
        x = x/10;
    }
    
    return sign * x_rev;
}
