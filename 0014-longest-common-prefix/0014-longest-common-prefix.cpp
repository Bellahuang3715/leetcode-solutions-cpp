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

    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";

        // Start with the first string as the initial prefix
        std::string prefix = strs[0];

        // Compare the prefix with each string
        for (int i = 1; i < strs.size(); i++) {
            // Keep trimming the prefix until it matches
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";  // No common prefix
            }
        }

        return prefix;
    }
};
