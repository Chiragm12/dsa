struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode& right;
};
TreeNode* SearchBst(TreeNode*root,int key){
    while(root!=nullptr&&root->val==key){
        if(root->val>key){
            root=root->left;
        }else{
            root=root->right;
        }
    }
}