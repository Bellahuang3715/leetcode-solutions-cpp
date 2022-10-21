class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        map<char, char> charMap;
        // Use a set to keep track of already mapped characters.
        set<char> set;
        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i], c2 = t[i];
            // char c1 has already been added as a key to the map
            if (charMap.find(c1) != charMap.end()) {
                if (charMap[c1] != c2) {
                    return false;
                }
            } 
            else {
                if (set.find(c2) != set.end())
                    return false;
                charMap[c1] = c2;
                set.insert(c2);
            }
        }
        return true;
    }
};
