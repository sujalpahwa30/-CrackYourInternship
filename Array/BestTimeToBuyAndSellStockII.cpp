#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int start = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (start < prices[i]) {
                max += prices[i] - start;
            }
            start = prices[i];
        }
        return max;
    }
};
int main() {
    Solution obj;
    vector<int> prices = {7,1,5,3,6,4};
    obj.maxProfit(prices);
}