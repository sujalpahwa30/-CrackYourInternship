#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixMod = 0;
        int result = 0;
        vector<int> modGroups(k);
        modGroups[0] = 1;
        for (int num : nums) {
            prefixMod = (prefixMod + num % k + k) % k;
            result += modGroups[prefixMod];
            modGroups[prefixMod]++;
        }
        return result;
    }
};
int main() {
    Solution obj;
    vector<int> arr = {4,5,0,-2,-3,1};
    int k = 5;
    obj.subarraysDivByK(arr , k);
}