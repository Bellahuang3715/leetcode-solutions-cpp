class Solution {
public:
    bool isValid(string s) {
        string stack;
        unordered_map<char, char> brackets {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
        };
        stack.push_back(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (brackets[stack.back()] == s[i]) {
                stack.pop_back();
            }
            else {
                stack.push_back(s[i]);
            }
        }
        return stack.size() ? 0 : 1;
    }
};
