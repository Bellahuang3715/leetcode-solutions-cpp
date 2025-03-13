/*
1046. Last Stone Weight

You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

*/


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Use a max-heap to always get the largest stones first.
        priority_queue<int> maxHeap;
        for (int stone : stones) {
            maxHeap.push(stone);
        }
        
        // Process stones until at most one remains.
        while (maxHeap.size() > 1) {
            // Get the two heaviest stones.
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();
            
            // If the stones are not equal, push the difference back.
            if (x != y) {
                maxHeap.push(y - x);
            }
        }
        
        // Return the weight of the last stone, or 0 if none remain.
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
