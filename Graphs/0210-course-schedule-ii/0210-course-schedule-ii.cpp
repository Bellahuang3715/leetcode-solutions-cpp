class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // 1) directed graph => nodes represent courses, edges represent prerequisites
    // 2) topological sorting => produce a linear ordering or vertices
        
/*
    Kahn's algorithm (for topological sorting)
    1) Graph representation
        - create an adjacency list to (list of list) to represent the graph
        - create an in-degree array to count how many prereqs each course has
    2) Find courses with no prereqs
        - add courses with degree 0 (no prereqs to a queue)
    3) Process courses in BFS order
        - take course from the queue and add to course order
        - for each dependednt course, reduce degree by 1 (1-less prereq)
        - depenedent's degree becomes 0, add it to the queue
    4) Check for cycles
        - if course order == total # courses, we've found an order
        - otherwise if there is cycle, it's impossible to finish all courses
*/
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0);    // size numCourses, initialized to 0
    
    // Build the graph and the in-degree array
    for (const auto& prereq : prerequisites)
    {
        int course = prereq[0];
        int prerequisite = prereq[1];
        graph[prerequisite].push_back(course);
        inDegree[course]++;
    }
    
    // Queue for courses with no prerequisites
    queue<int> zeroInDegree;
    for (int i = 0; i < numCourses; ++i)
    {
        if (inDegree[i] == 0)
        {
            zeroInDegree.push(i);
        }
    }
    
    vector<int> order;
    
    while (!zeroInDegree.empty())
    {
        int currentCourse = zeroInDegree.front();
        zeroInDegree.pop();
        order.push_back(currentCourse);
        
        // Decrease in-degree for neighboring courses
        for (int neighbor : graph[currentCourse])
        {
            inDegree[neighbor]--;
            // If in-degree becomes zero, add to the queue
            if (inDegree[neighbor] == 0)
            {
                zeroInDegree.push(neighbor);
            }
        }
    }
    
    // If order contains all courses, return it; otherwise, return empty
    if (order.size() == numCourses) {
        return order;
    } else {
        return {};
    }
    }
};