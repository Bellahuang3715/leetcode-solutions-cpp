class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;
        istringstream str(s1 + " " + s2);
        vector<string>result;
        while (str >> s1) {
            count[s1]++;
        }
        for (auto &word : count) {
            if (word.second == 1) {
                result.push_back(word.first);
            }
        }
        return result;
    }
};