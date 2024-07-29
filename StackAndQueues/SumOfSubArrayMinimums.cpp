class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<long long> dp(n, -1);
        vector<int>st;
        long long ans=0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i]<=arr[st.back()])
                st.pop_back();
            if (!st.empty()){
                int j=st.back();
                dp[i]=dp[j]+arr[i]*(i-j);
            }
            else dp[i]=arr[i]*(i+1);
            st.push_back(i);
            ans=(ans+dp[i]) % 1000000007;
        }
        return ans;   
    }
};