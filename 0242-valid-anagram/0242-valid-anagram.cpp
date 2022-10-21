class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> charCount;
        for (auto ch: s) {
            charCount[ch]++;
        }
        for (auto ch: t) {
            charCount[ch]--;
        }
        for (auto ele: charCount) {
            if (ele.second != 0) {
                return false;
            }
        }
        return true;
    }
};