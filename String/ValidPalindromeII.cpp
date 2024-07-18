#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s , int i , int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;
        while(i < j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                return isPalindrome(s , i , j-1) || isPalindrome(s , i+1 , j);
            }
        }
        return true;
    }
};