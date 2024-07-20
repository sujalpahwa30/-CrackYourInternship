#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool check(vector<int> &s , vector<int> &t){
        bool allPresent = true;
        for(int i = 0; i < 256; i++){
            if(t[i] > s[i]){
                allPresent = false;
                break;
            }
        }
        return allPresent;
    }
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        vector<int>tCount(256 , 0);
        vector<int>sCount(256 , 0);
        for(int i = 0; i < t.size(); i++){
            tCount[t[i]]++;
        }
        int start = 0;
        int end = 0;
        string ans = "";
        while(start <= end && end < s.size()){
            sCount[s[end]]++;
            while(start <= end && sCount[s[start]] >= tCount[s[start]]){
                string temp = s.substr(start , end-start+1);
                if(check(sCount , tCount) && (ans.size() > temp.size() || ans == "")){
                    ans = temp;
                }
                if(sCount[s[start]] == tCount[s[start]]) break;
                sCount[s[start]]--;
                start++;
            }
            end++;
        }
        return ans;
    }
};