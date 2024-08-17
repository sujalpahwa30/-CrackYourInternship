class Solution {
public:
    int dp[601][101][101] = {};
    int sub(vector<pair<int, int>>& a, int index, int nOnes, int nZeros) {
        int n = a.size();
        if (index == n or (nZeros == 0 and nOnes == 0)) return 0;
        if (dp[index][nOnes][nZeros] != -1) return dp[index][nOnes][nZeros];
        if (a[index].first > nOnes or a[index].second > nZeros) 
        return dp[index][nOnes][nZeros] = sub(a, index+1, nOnes, nZeros);

        int include = 1 + sub(a, index+1, nOnes - a[index].first, nZeros - a[index].second);
        int exclude = sub(a, index+1, nOnes, nZeros);
        return dp[index][nOnes][nZeros] = max(include, exclude);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> a;
        memset(dp, -1, sizeof(dp));
        for (auto i : strs) {
            int one = 0;
            int zero = 0;
            for (auto j : i) {
                if (j == '1') one++;
                else zero++;
            }
            a.push_back({one, zero});
        }
        int ans = sub(a, 0, n, m);
        return ans;
    }
};