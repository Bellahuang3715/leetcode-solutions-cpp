/*
207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build the graph and indegree count.
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            graph[prereq].push_back(course);
            indegree[course]++;
        }
        
        // Initialize queue with courses having no prerequisites.
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        // Process courses with no prerequisites.
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;  // Count this course as completed.
            for (int nextCourse : graph[course]) {
                // Remove the edge from course to nextCourse.
                indegree[nextCourse]--;
                // If nextCourse now has no prerequisites, add it to the queue.
                if (indegree[nextCourse] == 0)
                    q.push(nextCourse);
            }
        }
        
        // If count equals numCourses, all courses can be finished.
        return count == numCourses;
    }
};
