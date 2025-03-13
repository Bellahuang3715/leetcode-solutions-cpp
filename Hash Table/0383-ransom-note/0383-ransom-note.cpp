class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> charCount;
        for (auto c: magazine) {
            charCount[c]++;
        }
        for (auto c: ransomNote) {
            charCount[c]--;
        }
        for (auto ele: charCount) {
            if (ele.second < 0) {
                return false;
            }
        }
        return true;
    }
};

