/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumToLeafPath(TreeNode* root, int val)
    {
         if(root ==  NULL)
            return 0;
        val=10*val +root->val;
        
        if(root->left == NULL && root->right == NULL)
            return val;
        return sumToLeafPath(root->left,val)+sumToLeafPath(root->right,val);
    }
    int sumNumbers(TreeNode* root) {
        return sumToLeafPath(root,0);      
    }
};
