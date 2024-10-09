class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // count the frequency of each element
        unordered_map<int, int> eleFreq;
        for (int num : nums)
        {
            eleFreq[num]++;
        }
        
        // use minheap to keep the top k frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto& [num, freq] : eleFreq)
        {
            minHeap.push({freq, num});
            // remove element with the lowest frequency
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
    
        // extract the k most frequent elements
        vector<int> result;
        while (!minHeap.empty())
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};