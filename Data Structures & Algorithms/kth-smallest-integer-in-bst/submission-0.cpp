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
    int inorder(TreeNode* node, int& k){
        if(node==NULL)return 0;
        int l=inorder(node->left,k);
        if(l)return l;
        k--;
        if(k==0)return node->val;
        int r=inorder(node->right,k);
        if(r)return r;
        return 0;
        
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root,k);
    }
};
