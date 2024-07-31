class Solution {
public:
    bool areSame(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;
        return (root->val == subRoot->val && areSame(root->left, subRoot->left) && areSame(root->right, subRoot->right));
    }
    void traverse(TreeNode* root, TreeNode* subRoot, bool &ans) {
        if (ans) return;
        if (root->val == subRoot->val && areSame(root, subRoot)) {
            ans = true;
            return;
        }
        if (root->left) traverse(root->left, subRoot, ans);
        if (root->right) traverse(root->right, subRoot, ans);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;
        traverse(root, subRoot, ans);
        return ans;
    }
};