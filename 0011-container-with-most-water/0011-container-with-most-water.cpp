class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int area, length, width;
        int maxWater = 0;
        while (left < right) {
            length = min(height[left], height[right]);
            width = right - left;
            area = length * width;
            if (area > maxWater) {
                maxWater = area;
            }
            if (height[left] > height[right]) {
                right--;
            }
            else {
                left++;
            }
        }
        return maxWater;
    }
};

