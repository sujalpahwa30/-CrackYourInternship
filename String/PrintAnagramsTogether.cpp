#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<vector<string>> result;
        unordered_map<string , vector<string>> mp;
        for (int i = 0; i < string_list.size(); i++) {
            string s = string_list[i];
            sort(s.begin() , s.end());
            mp[s].push_back(string_list[i]);
        }
        for (auto itr = mp.begin(); itr != mp.end(); itr++) {
            result.push_back(itr->second);
        }
        return result;
    }
};