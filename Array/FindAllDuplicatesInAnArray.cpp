#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(nums[i] != nums[nums[i]-1]){
                swap(nums[i] , nums[nums[i]-1]);
            }
        }
        vector<int>v;
        for(int i = 0; i < n; i++){
            if(i+1 != nums[i]) v.push_back(nums[i]);
        }
        return v;
    }
};
int main() {
    Solution obj;
    vector<int> arr = {1,1,2};
    obj.findDuplicates(arr);
}