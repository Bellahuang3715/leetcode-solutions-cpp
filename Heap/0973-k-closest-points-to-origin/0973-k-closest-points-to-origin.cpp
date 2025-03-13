/*
973. K Closest Points to Origin

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
 
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Custom comparator for the max-heap.
        // It returns true if the distance of a is less than that of b.
        // This makes the point with the largest distance appear at the top.
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        };
        
        // Priority queue (max-heap) to store the k closest points.
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxHeap(cmp);
        
        // Process each point.
        for (const auto& point : points) {
            maxHeap.push(point);
            // Ensure the heap never contains more than k elements.
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        // Extract the points from the heap.
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top());
            maxHeap.pop();
        }
        
        return result;
    }
};
