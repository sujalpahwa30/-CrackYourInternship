bool cmp(vector<int> &i1 , vector<int> &i2){
    return i1[0] > i2[0];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin() , intervals.end());
        int lastEndTime = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < lastEndTime){
                ans++;
                lastEndTime = min(lastEndTime , intervals[i][1]);
            }
            else{
                lastEndTime = intervals[i][1];
            }
        }
        return ans;
    }
};