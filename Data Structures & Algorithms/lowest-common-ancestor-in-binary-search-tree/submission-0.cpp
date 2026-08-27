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
    TreeNode* lca(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node==NULL)return NULL;
        if(node->val==p->val){
            return p;
        }
        if(node->val==q->val)return q;
        
        TreeNode* left=lca(node->left, p, q);
        TreeNode* right=lca(node->right,p,q);
        if(left&&right)return node;
        if(left)return left;
        if(right)return right;
        return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p,q);
    }
};
