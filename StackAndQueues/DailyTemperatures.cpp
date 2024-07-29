class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>result(n , 0);
        vector<int>st;
        for(int i = n-1; i >= 0; i--){
            int currTemp = temperatures[i];
            while(!st.empty() && currTemp >= temperatures[st.back()]){
                st.pop_back();
            }
            if(!st.empty()){
                result[i] = st.back()-i;
            }
            st.push_back(i);
        }
        return result;
    }
};