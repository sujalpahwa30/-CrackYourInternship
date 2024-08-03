class BSTIterator {
    stack<TreeNode*> st;
    void pushAll(TreeNode* node) {
        for (; node != NULL; st.push(node), node=node->left);
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmpNode = st.top();
        st.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
