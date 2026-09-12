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
    int ans=-1e9;
    int path( TreeNode* node){
        if(node==NULL){
            return 0;
        }
        int left=max(0,path(node->left));
        int right=max(0,path(node->right));
        int a=node->val+left+right;
        int b=node->val+max(left,right);
        int k=max(a,b);
        ans=max(ans,k);
        return b;
    }
public:
    int maxPathSum(TreeNode* root) {
        int k=path(root);
        return ans;
    }
};
