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



/*

*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm> // For std::sort

using namespace std;

int main() {
    // Example unordered_map
    unordered_map<string, int> myMap = {
        {"apple", 5},
        {"banana", 3},
        {"orange", 8},
        {"grape", 1}
    };

    // Step 1: Copy elements to a vector of pairs
    vector<pair<string, int>> sortedVector(myMap.begin(), myMap.end());

    // Step 2: Sort the vector by value (ascending order)
    sort(sortedVector.begin(), sortedVector.end(), 
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second < b.second; // Compare by value
         });

    // Step 3: Print the sorted key-value pairs
    cout << "Sorted by value:" << endl;
    for (const auto& pair : sortedVector) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
