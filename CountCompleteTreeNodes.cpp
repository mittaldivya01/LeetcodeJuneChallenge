int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        return 1 + countNodes(root->left) +countNodes(root->right);
    }
};
