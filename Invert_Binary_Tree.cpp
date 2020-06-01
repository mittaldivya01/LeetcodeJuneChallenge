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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q1;
        TreeNode* temp=nullptr;
        TreeNode* head=root;
        if(root == nullptr)
            return root;
        
            q1.push(root);
        while(!q1.empty()){
                  if(root->left != nullptr || root->right != nullptr){
                        temp=root->left;
                        root->left=root->right;
                        root->right=temp;
                }
            if(root->left!=nullptr &&(root->left->left != nullptr || root->left->right != nullptr))
                q1.push(root->left);
            if(root->right!=nullptr && (root->right->left != nullptr || root->right->right != nullptr ))
                q1.push(root->right);
            q1.pop();
            root=q1.front();
         }
        
        return head;
    }
};
