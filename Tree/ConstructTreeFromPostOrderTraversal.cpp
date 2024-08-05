struct Node *constructTreeUtil(int pre[], char preLN[], int *index_ptr, int n) {
    int index = *index_ptr; 
    if (index == n)
        return NULL;
    struct Node *temp = new Node(pre[index]);
    (*index_ptr)++; 
    if (preLN[index] == 'N') 
    {
        temp->left = constructTreeUtil(pre, preLN, index_ptr, n); 
        temp->right = constructTreeUtil(pre, preLN, index_ptr, n); 
    }
    return temp; 
}
struct Node *constructTree(int n, int pre[], char preLN[]) {
    int index = 0; 
    return constructTreeUtil(pre, preLN, &index, n); 
}
