/*
438. Find All Anagrams in a String

Given two strings s and p, return an array of all the start indices of p's 
anagrams
 in s. You may return the answer in any order.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;

        vector<int> pCount(26, 0), windowCount(26, 0);

        // Fill frequency of characters in p
        for (char c : p) {
            pCount[c - 'a']++;
        }

        int windowSize = p.size();

        for (int i = 0; i < s.size(); ++i) {
            // Add the current character to the window
            windowCount[s[i] - 'a']++;

            // Remove the character that is no longer in the window
            if (i >= windowSize) {
                windowCount[s[i - windowSize] - 'a']--;
            }

            // Compare windowCount and pCount
            if (windowCount == pCount) {
                result.push_back(i - windowSize + 1);
            }
        }

        return result;
    }
};
