class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        
        while (l <= r) {
            long int mid = l + (r - l) / 2;
            long int mid_squared = mid * mid;
            if (mid_squared == x) {
                return mid;
            } else if (mid_squared > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        // if we reached here, then l*l must be greater than x
        // therefore, the required ans is l-1
        return l-1;
    }
};
