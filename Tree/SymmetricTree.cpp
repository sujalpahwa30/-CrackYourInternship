class Solution {
public:
    bool same(TreeNode* nodeA , TreeNode* nodeB){
        if(nodeA == NULL && nodeB == NULL) return true;
        if(nodeA == NULL || nodeB == NULL || nodeA->val != nodeB->val) return false;
        return same(nodeA->left , nodeB->right) && same(nodeA->right , nodeB->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return same(root->left , root->right);
    }
};