class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        
        int a = 0, b = 1, temp;
        
        for (int i=0; i<n-1; i++) {
            temp = b;
            b = a + b;
            a = temp;
        }
        
        return b;
    }
};
