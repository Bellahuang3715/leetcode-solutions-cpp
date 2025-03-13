/*
209. Minimum Size Subarray Sum

Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.


Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0


*/

#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return ""; // Edge case: Empty input

        // Frequency map for characters in t
        unordered_map<char, int> freqMap;
        for (char c : t) freqMap[c]++;
        
        int required = freqMap.size(); // Number of unique characters to match
        int left = 0, right = 0;       // Sliding window pointers
        int formed = 0;                // Number of characters currently matched
        unordered_map<char, int> windowCounts; // Frequency map for the current window

        int minLen = INT_MAX;          // Minimum length of valid window
        int start = 0;                 // Start index of the minimum window

        while (right < s.length()) {
            // Expand the window by adding s[right]
            char c = s[right];
            windowCounts[c]++;

            // Check if the character in s matches the frequency required in t
            if (freqMap.count(c) && windowCounts[c] == freqMap[c]) {
                formed++;
            }

            // Try to shrink the window
            while (left <= right && formed == required) {
                // Update the result if the current window is smaller
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove s[left] from the window and shrink
                char removedChar = s[left];
                windowCounts[removedChar]--;
                if (freqMap.count(removedChar) && windowCounts[removedChar] < freqMap[removedChar]) {
                    formed--;
                }
                left++; // Shrink the window
            }

            // Expand the window
            right++;
        }

        // If no valid window was found, return an empty string
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
