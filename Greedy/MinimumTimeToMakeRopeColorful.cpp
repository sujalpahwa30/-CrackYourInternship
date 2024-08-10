class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int mini = 0;
        int i = 0;
        int j = 1;
        while (j < n) {
            if (colors[i] == colors[j]) {
                mini += min(neededTime[i], neededTime[j]);
                if (neededTime[i] < neededTime[j]) {
                    i = j;
                    j++;
                } 
                else j++;
                }
            else {
                    i = j;
                    j++;
                }
            } 
        return mini;
    }
};