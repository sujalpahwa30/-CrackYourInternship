#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int minr = 0 , minc = 0;
        int maxr = m-1 , maxc = n-1;
        int tne = n*m;
        int count = 0;
        vector<int>v;
        while(minr <= maxr && minc <= maxc) {
            for(int j = minc; j <= maxc && count < tne; j++){
                v.push_back(matrix[minr][j]);
                count++;
            }
            minr++;
            for(int i = minr; i <= maxr && count < tne; i++){
                v.push_back(matrix[i][maxc]);
                count++;
            }
            maxc--;
            for(int j = maxc; j >= minc && count < tne; j--){
                v.push_back(matrix[maxr][j]);
                count++;
            }
            maxr--;
            for(int i = maxr; i >= minr && count < tne; i--){
                v.push_back(matrix[i][minc]);
                count++;
            }
            minc++;
        }
        return v;
    }
};