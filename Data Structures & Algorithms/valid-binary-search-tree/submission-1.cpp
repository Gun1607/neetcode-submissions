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
    bool validbst(TreeNode* node, int llim, int rlim){
        if(node==NULL)return true;
        if(node->val<=llim||node->val>=rlim)return false;
        if(!validbst(node->left,llim,node->val))return false;
        if(!validbst(node->right,node->val,rlim))return false;

        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return validbst(root,-1e9,1e9);
    }
};
