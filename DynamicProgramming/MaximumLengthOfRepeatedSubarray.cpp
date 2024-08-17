class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, 0));
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    memo[i][j] = memo[i+1][j+1] + 1;
                    ans = max(ans, memo[i][j]);
                }
            }
        }
        return ans;
    }
};