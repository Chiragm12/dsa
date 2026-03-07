/*
so what happens, is that we know the rule that |left tree-right tree| should be less than 1 or 0, so we check that, in that imaage
that max(lh,rh)+1, goes initally to the last node, and keeps going up, and check alongside the rgiht node, to check if lh-rh>1, so the 
third node from the left which is 2-0 is 2, greater than 1 hence it retuns -1.
*/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

    int checkHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1;

        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1) return -1;

        return max(leftHeight, rightHeight) + 1;
    }
};

