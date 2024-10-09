class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        int i = 0;
        int n = intervals.size();
        
        // add all intervals that end before newInterval starts
        while (i < n && intervals[i][1] < newInterval[0])
        {
            merged.push_back(intervals[i]);
            i++;
        }
        
        // merge overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        merged.push_back(newInterval);
        
        // add all intervals that start after newInterval ends
        while (i < n)
        {
            merged.push_back(intervals[i]);
            i++;
        }
        
        return merged;        
    }
};