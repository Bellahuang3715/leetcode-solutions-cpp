/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
*/

class Solution {
public:

    void backtrack(vector<string>& result, string current, int open, int close, const int& n)
    {
        if (current.length() == n * 2)
        {
            result.push_back(current);
            return;
        }
        if (open < n)
        {
            backtrack(result, current + "(", open+1, close, n);
        }
        if (close < open)
        {
            backtrack(result, current + ")", open, close+1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        // some recursive logic
        backtrack(result, "", 0, 0, n);
        return result;
    }
};