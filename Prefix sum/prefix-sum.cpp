int countSubarraysWithSum(vector<int>& nums, int K) {
    // Hash map to store prefix sums and their frequencies
    unordered_map<int, int> prefixSumFreq;
    prefixSumFreq[0] = 1; // To handle cases where prefix[i] == K

    int prefixSum = 0;
    int count = 0;

    for (int num : nums) {
        // Update the prefix sum
        prefixSum += num;

        // Check if there's a prefix sum that satisfies the condition
        int target = prefixSum - K;
        if (prefixSumFreq.find(target) != prefixSumFreq.end()) {
            count += prefixSumFreq[target];
        }

        // Update the frequency of the current prefix sum
        prefixSumFreq[prefixSum]++;
    }

    return count;
}