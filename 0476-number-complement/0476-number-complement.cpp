class Solution {
public:
    int findComplement(int num) {
        vector<int> temp;
        while (num != 0) {
            temp.push_back(num % 2);
            num /= 2;
        }
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == 1) {
                temp[i] = 0;
            }
            else {
                temp[i] = 1;
            }
        }
        int result = 0;
        for (int i = temp.size()-1; i >= 0; i--) {
            result = result * 2 + temp[i];
        }
        return result;
    }
};