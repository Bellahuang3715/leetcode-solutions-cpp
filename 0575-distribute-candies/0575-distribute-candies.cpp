class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> kinds;
        for (int kind : candyType) {
            kinds.insert(kind);
        }
        return min(kinds.size(), candyType.size() / 2);
    }
};