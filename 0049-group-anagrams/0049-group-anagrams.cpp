class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // hash map
        unordered_map<string, vector<string>> strMap;
        for (auto& str : strs)
        {
            string word = str;
            sort(word.begin(), word.end());
            strMap[word].push_back(str);
        }
        
        vector<vector<string>> result;
        for (auto& group : strMap)
        {
            result.push_back(group.second);
        }
        return result;
    }
};