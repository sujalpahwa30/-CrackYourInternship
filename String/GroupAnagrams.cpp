#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(string str : strs){
            string lexo = str;
            sort(lexo.begin() , lexo.end());
            if(mp.find(lexo) == mp.end()){
                vector<string>v;
                v.push_back(str);
                mp[lexo] = v;
            }
            else{
                mp[lexo].push_back(str);
            }
        }
        for(auto x : mp){
            vector<string>v = x.second;
            ans.push_back(v);
        }
        return ans;
    }
};