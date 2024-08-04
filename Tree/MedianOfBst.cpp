void storeInorder(vector<int> &inorder,struct Node* root) {
    if(!root)
        return ;
    
    storeInorder(inorder,root->left);
    inorder.push_back(root->data);
    storeInorder(inorder,root->right);
}
float findMedian(struct Node *root) {
      vector<int> inorder;
      storeInorder(inorder,root);
      int n = inorder.size();
      
      if(n&1){
          return inorder[(n+1)/2 -1];
      }
      else{
          return (inorder[n/2 -1] + inorder[n/2 +1 -1])/2.0;
      }
}
