class Solution{
  public:
    void make(set<int> &l,set<int> &n,Node *root) {
        if(root==NULL)
            return;
        n.insert(root->data);
        if(root->left==NULL and root->right==NULL) {
            l.insert(root->data);
            return;
        }
        make(l,n,root->left);
        make(l,n,root->right);
    }
    bool isDeadEnd(Node *root) {
        set<int> leaf,node;
        make(leaf,node,root);
        node.insert(0);
        for(auto i = leaf.begin();i!=leaf.end();i++) {
            int ii = (*i);
            if(node.find(ii-1)!=node.end() and node.find(ii+1)!=node.end())
                return true;
        }
        return false;
    }
};
