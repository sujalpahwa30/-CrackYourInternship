#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
           int correctIdx = nums[i]; 
           if (nums[correctIdx] == nums[i]) return nums[i];
           else swap(nums[correctIdx] , nums[i]);
        }
        return 1;
    }
};
int main() {
    Solution obj;
    vector<int> arr = {1,2,3,3,4};
    int duplicateValue = obj.findDuplicate(arr);
    cout << duplicateValue;
    return 0;
}