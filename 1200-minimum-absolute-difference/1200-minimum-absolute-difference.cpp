class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min = abs(arr[1] - arr[0]), current = 0;
        for (int i = 0; i < arr.size()-1; i++) {
            current = arr[i+1] - arr[i];
            if (current < min) {
                min = current;
            }
        }
        vector<vector<int>> result;
        for (int i = 0; i < arr.size()-1; i++) {
            current = arr[i+1] - arr[i];
            if (current == min) {
                result.push_back({arr[i], arr[i+1]});
            }
            
        }
        return result;
    }
};