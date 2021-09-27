class Solution {
public:
    /*
    int climbStairs(int n) {
        vector<int> num_ways(n+1, 0);
        num_ways[n] = 1; // only one way to reach nth step from n - by not moving
        num_ways[n-1] = 1; // by taking one step
        
        for (int i=n-2; i>=0; i--) {
            num_ways[i] = num_ways[i+1] + num_ways[i+2];
        }
        
        return num_ways[0];
    }
    */
    
    int climbStairs(int n) {
        int a = 1, b = 1, temp;
        
        for (int i=n-2; i>=0; i--) {
            temp = a;
            a = a + b;
            b = temp;
        }
        
        return a;
    }
};

