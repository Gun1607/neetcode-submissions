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
    int depth(TreeNode* node){
        if(node==NULL)return 0;
        int l=depth(node->left);
        int r=depth(node->right);
        return 1+max(l,r);
    }
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        return depth(root);
    }
};
