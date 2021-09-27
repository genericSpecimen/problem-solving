class Solution {
public:
    /*
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i=0; i<8*sizeof(n); i++) {
            if (n & 1 == 1) {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
    */
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while (n != 0) {
            n = n & (n-1);
            count++;
        }
        
        return count;
    }
};
