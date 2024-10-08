class Solution {
public:
    int sumOfSquares(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n)
    {
        int slow = n;
        int fast = sumOfSquares(n);  // Fast moves two steps at a time
        
        while (fast != 1 && slow != fast) {
            slow = sumOfSquares(slow);        // Slow moves one step
            fast = sumOfSquares(sumOfSquares(fast));  // Fast moves two steps
        }
        
        return fast == 1;  // If fast reaches 1, n is a happy number
    }
};