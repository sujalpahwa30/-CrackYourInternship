class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        for (int num : nums2) {
            while(!st.empty() && st.top() < num) {
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        vector<int> result(nums1.size());
        for (size_t i = 0; i < nums1.size(); i++) {
            result[i] = mp.count(nums1[i]) ? mp[nums1[i]] : -1;
        }
        return result;
    }
};