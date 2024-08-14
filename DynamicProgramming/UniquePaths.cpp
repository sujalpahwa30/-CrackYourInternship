class Solution {
public:
    int n , m;
    vector<vector<int>>dp;
    int f(int i , int j){
        if(i == n-1 and j == m-1) return 1;
        if(i < 0 or j < 0 or i >= n or j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = f(i , j+1) + f(i+1 , j);
    }
    int uniquePaths(int M, int N) {
        n = M;
        m = N;
        dp.clear();
        dp.resize(105 , vector<int>(105 , -1));
        return f(0 , 0);
    }
};