class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int lenFirstStr = strs[0].size();
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            int lenCurrentStr = strs[i].size();
            while (j < lenCurrentStr && strs[i][j] == strs[0][j]) {
                j++;
            }
            lenFirstStr = min(lenFirstStr, j);
        }
        return strs[0].substr(0, lenFirstStr);
    }
};
