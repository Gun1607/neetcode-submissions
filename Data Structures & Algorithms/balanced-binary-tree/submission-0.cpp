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
    int balanced(TreeNode* node, bool& ans){
        if(node==NULL)return 0;
        int l=balanced(node->left,ans);
        int r=balanced(node->right,ans);
        if(abs(l-r)>=2)ans=false;
        return max(l,r)+1;
    }

public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        bool ans=true;
        int x=balanced(root,ans);
        return ans;
    }
};
