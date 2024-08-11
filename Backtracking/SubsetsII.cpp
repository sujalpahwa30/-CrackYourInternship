class Solution {
public:

void subsetsWithDup(vector<int>& nums , vector<vector<int>>& ans , vector<int>& temp , int idx){
    if(idx == nums.size()){
        ans.push_back(temp);
        return;
    }
    int i = idx+1;
    while(i < nums.size() && nums[i] == nums[i-1]){
        i++;
    }
    subsetsWithDup(nums , ans , temp , i);
    temp.push_back(nums[idx]);
    subsetsWithDup(nums , ans , temp , idx+1);
    temp.pop_back();

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin() , nums.end());
        subsetsWithDup(nums , ans , temp , 0);
        return ans;
  }
};