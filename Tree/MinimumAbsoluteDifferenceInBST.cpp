class Solution {
public:
    void inorder(TreeNode* root , vector<int>& ans){
        if(root == NULL) return;
        inorder(root->left , ans);
        ans.push_back(root->val);
        inorder(root->right , ans);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>ans;
        inorder(root ,ans);
        int n = ans.size();
        int a = INT_MAX;
        for(int i = 0; i < n-1; i++){
            a = min(a , abs(ans[i+1] - ans[i]));
        }
        return a;
    }
};