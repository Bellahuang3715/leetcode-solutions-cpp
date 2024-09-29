class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // use sliding window
        unordered_set<char> charSet;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            // if the current character is already in the set, shrink the window
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            // update the maximum length of the substring found so far
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};