#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int steps = 0;
        sort(nums.begin() , nums.end());
        int median = nums[n/2];
        for (int i = 0; i < n; i++) {
            steps += abs(nums[i] - median);
        }
        return steps;
    }
};