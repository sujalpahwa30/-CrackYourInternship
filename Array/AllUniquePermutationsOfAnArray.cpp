#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
  public:
    void generator(vector<int> curr , vector<vector<int>>& result , int i , vector<int> A , map<vector<int>,int>& hash) {
        if (curr.size() == A.size()) {
            if(hash.find(curr) == hash.end()) {
                result.push_back(curr);
                hash[curr] = 1;
            }
            return;
        }
        else {
            for (int j = i; j < A.size(); j++) {
                curr.push_back(A[j]);
                swap(A[i] , A[j]);
                generator(curr , result , i+1 , A , hash);
                curr.pop_back();
                swap(A[i] , A[j]);
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<int> curr;
        vector<vector<int>> result;
        map<vector<int>,int> hash;
        generator(curr , result , 0 , arr , hash);
        sort(result.begin() , result.end());
        return result;
    }
};