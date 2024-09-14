class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> seqMap;
        if (s.size() < 10) return {};   // empty vector
        
        for (int i = 0; i < (s.size() - 9); i++)
        {
            string str = s.substr(i, 10);
            seqMap[str]++;
        }
        
        vector<string> result;
        for (auto& seq : seqMap)
        {
            if (seq.second > 1)
                result.push_back(seq.first);
        }
        return result;
    }
};