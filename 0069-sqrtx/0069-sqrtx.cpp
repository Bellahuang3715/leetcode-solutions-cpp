class Solution {
public:
    int mySqrt(int x) {
        // binary search
        int left = 0, right = x;
        while (left <= right)
        {
            long long mid = (left + right) / 2;
            if ((mid * mid) < x)
            {
                left = mid + 1;
            }
            else if ((mid * mid) > x)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return right;
    }
};