class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) { return result; }
        
        // <sum, index1, index2>
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        
        // initiliaze the minheap with first k elements
        for (int i = 0; i < nums1.size() && i < k; i++)
        {
            // form pairs using nums2[0] & all elements in nums1
            minHeap.push(make_tuple(nums1[i] + nums2[0], i, 0));
        }
        
        // extract pairs from the heap until we've found k pairs
        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();

            result.push_back({nums1[i], nums2[j]});

            // If there's a next element in nums2 for the current i, push the next pair (nums1[i], nums2[j+1])
            if (j + 1 < nums2.size()) {
                minHeap.push(make_tuple(nums1[i] + nums2[j + 1], i, j + 1));
            }
        }

        return result;
    }
};