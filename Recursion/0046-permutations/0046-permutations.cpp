/*
46. Permutations

Given an array nums of distinct integers, return all the possible 
permutations
. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 
*/

class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            // Swap the current element with the element at the current index
            swap(nums[index], nums[i]);
            // Recursively permute the remaining elements (index + 1)
            backtrack(nums, index + 1, result);
            // Backtrack: undo the swap to try the next permutation
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
};



// FOR COMBINATIONS:

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(n, k, 1, combination, result);
        return result;
    }

private:
    void backtrack(int n, int k, int start, vector<int>& combination, vector<vector<int>>& result) {
        // If the combination is of size k, add it to the result
        if (combination.size() == k) {
            result.push_back(combination);
            return;
        }

        // Try every number starting from 'start' to 'n'
        for (int i = start; i <= n; i++) {
            combination.push_back(i); // Add the current number to the combination
            backtrack(n, k, i + 1, combination, result); // Recurse with the next number
            combination.pop_back(); // Backtrack: remove the current number
        }
    }
};


// FOR SUBSETS!!!


#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(nums, 0, subset, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(subset);

        // Try adding each element starting from 'index' to the subset
        for (int i = index; i < nums.size(); i++) {
            subset.push_back(nums[i]); // Add the current element to the subset
            backtrack(nums, i + 1, subset, result); // Recurse to add the next element
            subset.pop_back(); // Backtrack: remove the current element
        }
    }
};
