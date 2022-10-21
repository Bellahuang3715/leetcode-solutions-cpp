class Solution {
public:
    int countSegments(string s) {
        istringstream str(s);
        string newString;
        int count = 0;
        while (str >> newString) {
            count++;
        }
        return count;
    }
};