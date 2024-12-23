class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // greedy algorithm
        int total_gas = 0;
        int current_gas = 0;
        int start_index = 0;
        
        for (int i = 0; i < gas.size(); i++)
        {
            total_gas += gas[i] - cost[i];
            current_gas += gas[i] - cost[i];
            
            // no more gas, reset the starting position
            if (current_gas < 0)
            {
                start_index = i+1;
                current_gas = 0;
            }
        }
        return total_gas >= 0 ? start_index : -1;
    }
};