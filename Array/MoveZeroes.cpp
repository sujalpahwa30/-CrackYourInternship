#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-1-i; j++) {
                if (nums[j] == 0) {
                    swap(nums[j] , nums[j+1]);
                }
            }
        }
    }
};
int main() {
    Solution obj;
    vector<int> arr = {0,1,0,3,12};
    obj.moveZeroes(arr);
    return 0;
}