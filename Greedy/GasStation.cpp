class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s1 = accumulate(gas.begin(), gas.end(), 0);
        int s2 = accumulate(cost.begin(), cost.end(), 0);
        if (s1 < s2) return -1;
        int n = gas.size();
        int curr = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (curr < 0) {
                curr = 0;
                start = i;
            }
            curr += gas[i] - cost[i];
        }
        return start;
    }
};