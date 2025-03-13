class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // std::greater => smallest ele at the top
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap(nums.begin(), nums.begin() + k);
        
        for (int i = k; i < nums.size(); i++) {
            // if find a number that is greater than smallest val in minheap
            if (nums[i] > min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        // the smallest val in the heap is the kth largest
        // since there are always k elements in the heap
        return min_heap.top();
    }
};