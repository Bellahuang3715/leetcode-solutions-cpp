class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // start from the last index of nums1
        int index = m + n - 1;
        int i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
                nums1[index--] = nums1[i--];
            else
                nums1[index--] = nums2[j--];
        }
        
        // if there are any eles left in nums2, fill it in
        while (j >= 0)
            nums1[index--] = nums2[j--];
    }
};