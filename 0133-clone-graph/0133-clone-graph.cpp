/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* cur, unordered_map<Node*, Node*>& mp)
    {
        vector<Node*> neighbor;
        Node* clone = new Node(cur->val);
        mp[cur] = clone;
        for (auto it : cur->neighbors)
        {
            // neighbor has already been cloned
            // simply at it to the neighbors list
            if (mp.find(it) != mp.end())
            {
                neighbor.push_back(mp[it]);
            }
            // neighbor has not been cloned
            // traverse on that neighbor
            else
            {
                neighbor.push_back(dfs(it, mp));
            }
        }
        clone->neighbors = neighbor;
        return clone;
    }
    
    Node* cloneGraph(Node* node) {
        // recursion type question on graphs - dfs or bfs
        // IDEA: start at root node, traverse as far as possible before backtracking
        unordered_map<Node*, Node*> mp;
        if (node == NULL) { return NULL; }
        // only one node, no neighbors
        if (node->neighbors.size() == 0)
        {
            Node* clone = new Node(node->val);
            return clone;
        }
        return dfs(node, mp);
    }
};