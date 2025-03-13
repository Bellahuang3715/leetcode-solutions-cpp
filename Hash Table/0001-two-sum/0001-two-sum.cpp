class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index = 1;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1 + i; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                }
                //index++;
            }
           // index--;
        }
        return result;
    }
};

// O(n) solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // Calculate the required complement
            if (hashMap.find(complement) != hashMap.end()) {
                // If complement exists, return indices
                return {hashMap[complement], i};
            }
            // Otherwise, store the current number and its index
            hashMap[nums[i]] = i;
        }
        return {}; // If no solution is found (though it's guaranteed to exist)
    }
};
