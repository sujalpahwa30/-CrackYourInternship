#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int , int> m;
        for (int i = 0; i < n; i++) {
            int rem = target - nums[i];
            if (m.find(rem) != m.end()) {
                ans.push_back(m[rem]);
                ans.push_back(i);
            }
            else m[nums[i]] = i;
        }
        return ans;
    }
};
int main() {
    Solution obj;
    vector<int> ans = {2,7,11,15};
    int target = 9;
    obj.twoSum(ans , target);
}