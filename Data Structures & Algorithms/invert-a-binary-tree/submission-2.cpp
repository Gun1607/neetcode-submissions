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
    TreeNode* invert(TreeNode* node){
        if(node->left==NULL&&node->right==NULL)return node;
        if(node->left==NULL){
            node->left=invert(node->right);
            node->right=NULL;
            return node;
        }
        if(node->right==NULL){
            node->right=invert(node->left);
            node->left=NULL;
            return node;
        }
        TreeNode* lft=invert(node->left);
        TreeNode* rt=invert(node->right);
        node->right=lft;
        node->left=rt;
        return node;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return root;
        //return root;
        return invert(root);
    }
};
