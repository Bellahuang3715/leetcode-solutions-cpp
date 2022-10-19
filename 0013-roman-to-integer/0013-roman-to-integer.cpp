class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> converter {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (converter[s[i]] < converter[s[i+1]]) {
                count -= converter[s[i]];
            }
            else {
                count += converter[s[i]];            
            }
        }
        return count;
    }
};

