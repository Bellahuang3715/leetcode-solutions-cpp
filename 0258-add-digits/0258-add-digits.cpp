class Solution {
public:
    int addDigits(int num) {
        // recursive method
        int sum = 0;
        while (num) {
            sum += (num % 10);
            num /= 10;
        }
        if (sum < 10)
            return sum;
        else
            return addDigits(sum);
    }
};