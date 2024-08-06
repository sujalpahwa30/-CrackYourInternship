#define pp pair<int , int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
        for(int ele : nums){
            mp[ele]++;
        }
        priority_queue<pp , vector<pp> , greater<pp>>pq;
        for(auto x : mp){
            int ele = x.first;
            int freq = x.second;
            pq.push({freq , ele});
            if(pq.size() > k) pq.pop();
        }
        vector<int>ans;
        while(pq.size() > 0){
            int x = pq.top().second;
            ans.push_back(x);
            pq.pop();
        }
        return ans;
    }
};