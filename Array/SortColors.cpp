#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0;
        int mid = 0;
        int hi = nums.size() - 1;
        while (mid <= hi) {
            if (nums[mid] == 0) {
                swap(nums[mid] , nums[lo]);
                mid++;
                lo++;
            } else if (nums[mid] == 1) mid++;
            else {
                swap(nums[mid] , nums[hi]);
                hi--;
            }
        }
    }
};
int main() {
    Solution obj;
    vector<int> arr = {2,0,1};
    obj.sortColors(arr);
    return 0;
}