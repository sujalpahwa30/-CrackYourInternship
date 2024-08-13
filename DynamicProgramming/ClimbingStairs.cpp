class Solution {
public:
    vector<int>dp;
    int f(int i){
        if(i == 1) return 1;
        if(i == 2 or i == 3) return i;
        if(dp[i] != -1) return dp[i];
        return dp[i] = f(i-1) + f(i-2);
    }
    int climbStairs(int n) {
        dp.clear();
        dp.resize(105 , -1);
        return f(n);
    }
};