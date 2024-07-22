#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<long long int>
    productExceptSelf(vector<long long int>& nums, int n)
    {
        long long prod = 1;
        long long flag = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                flag++;
            else
                prod *= nums[i];
        }
        for (int i = 0; i < n; i++) {
            if (flag > 1)
                nums[i] = 0;
            else if (flag == 0)
                nums[i] = (prod / nums[i]);
            else if (flag == 1 && nums[i] != 0)
                nums[i] = 0;
            else
                nums[i] = prod;
        }
        return nums;
    }
};
