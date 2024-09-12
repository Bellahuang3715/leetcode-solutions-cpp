class Solution {
public:
    int climbStairs(int n) {
        // numWays(n) = numWays(n-1) + numWays(n-2)
        
        // base case
        if (n <= 1) return 1;
        
        // prev1 = ways to get to step 1
        // prev2 = ways to get to step 0
        int prev1 = 1, prev2 = 1;       // prev1 = (n-1), prev2 = (n-2)
        int numWays = 0;
        
        for (int i = 2; i <= n; i++)
        {
            numWays = prev1 + prev2;
            prev2 = prev1;
            prev1 = numWays;
        }
        
        return numWays;
    }
};