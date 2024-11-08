class Solution {
public:
    void expandAroundCentre(const string& s, int left, int right, int& start, int& maxLength)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        
        int length = right - left - 1;
        if (length > maxLength)
        {
            maxLength = length;
            start = left + 1;
        }
    }
    
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLength = 1;
        
        // iterate over all possible centres
        for (int i = 0; i < s.size(); i++)
        {
            // odd length palindrome centered at i
            expandAroundCentre(s, i, i, start, maxLength);
            
            // even length palinedrome centered at i, i+1
            expandAroundCentre(s, i, i+1, start, maxLength);
        }
        return s.substr(start, maxLength);
    }
};