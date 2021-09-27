/*
int reverse_nonnegative(int x) {
    const int MAX = std::numeric_limits<int>::max();
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

    return x_rev;
}

bool isPalindrome(int x) {
    if (x >= 0 && x == reverse_nonnegative(x)) {
        return true;
    }
    return false;
}
*/

/*
    * num_digits = floor(log_10(x)) + 1;
    * LSD = x % 10
    * MSD = x / 10^(num_digits-1)
    * 
    * O(n) time complexity, n = num_digits
    * O(1) space complexity.
    */

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    if (x == 0) {
        return true; 
    }
    
    int num_digits = floor(log10(x)) + 1;
    //std::cout << num_digits << "\n";
    int msd_mask = static_cast<int>(pow(10, num_digits-1));
    for (int i=0; i<num_digits/2; i++) {
        if ( (x / msd_mask) != (x % 10)) {
            return false;
        }
        // strip the LSD and MSD
        x = x % msd_mask;
        x = x / 10;
        msd_mask = msd_mask / 100;
    }
    
    return true;
}
