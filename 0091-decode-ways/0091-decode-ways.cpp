class Solution {
public:
    int numDecodings(string s) {
        // dynamic programming problem, since
        // 1) each part of the problem depends on solutions to smaller parts
        // 2) we can build the solution step by step, reusing results alr computed
        
        int n = s.size();
        if (n == 0 || s[0] == '0') { return 0; }
        
        // DP array to store the number of ways to decode up to each index
        std::vector<int> dp(n+1, 0);
        // base case: one way to decode an empty string (do nothing)
        dp[0] = 1;
        dp[1] = (s[0] != '0') ? 1 : 0;
        
        for (int i = 2; i <= n; i++)
        {
            // check the single-digit decode possibility
            if (s[i - 1] >= '1' && s[i - 1] <= '9')
            {
                dp[i] += dp[i - 1];
            }
            // check the two-digit decode possibility
            int twoDigit = std::stoi(s.substr(i - 2, 2));
            if (twoDigit >= 10 && twoDigit <= 26)
            {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};