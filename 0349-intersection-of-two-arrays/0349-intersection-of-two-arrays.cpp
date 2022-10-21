class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> result;
        // unordered_set<int>::iterator it;
        for (auto num : nums2) {
            if (set.count(num)) {
                result.push_back(num);
                set.erase(num);
            }
        }
        return result;
    }
};