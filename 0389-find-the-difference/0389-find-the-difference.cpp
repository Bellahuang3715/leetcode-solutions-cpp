class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> charCount;
        for (auto str: s) {
            charCount[str]++;
        }
        for (auto str: t) {
            charCount[str]--;
        }
        for (auto ele: charCount) {
            if (ele.second != 0) {
                return ele.first;
            }
        }
        return NULL;
    }
};