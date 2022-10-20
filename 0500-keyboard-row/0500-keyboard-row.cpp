class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        unordered_set firstRow = { 'q','Q','w','W','e','E','r','R','t','T','y','Y','u','U','i','I','o','O','p','P' };
		unordered_set secondRow = { 'a','A','s','S','d','D','f','F','g','G','h','H','j','J','k','K','l','L'};
		unordered_set thirdRow = { 'z','Z','x','X','c','C','v','V','b','B','n','N','m','M'};
        for (auto word: words) {
            bool row1 = true, row2 = true, row3 = true;
            
            for (auto ch: word) {
                if (row1 == true) {
                    auto it = firstRow.find(ch);
                    if (it == firstRow.end()) {
                        row1 = false;
                    }
                }
                if (row2 == true) {
                    auto it = secondRow.find(ch);
                    if (it == secondRow.end()) {
                        row2 = false;
                    }
                }
                if (row3 == true) {
                    auto it = thirdRow.find(ch);
                    if (it == thirdRow.end()) {
                        row3 = false;
                    }
                }
            }
            if (row1 || row2 || row3) {
                result.push_back(word);
            }
        }
        return result;
    }
};

