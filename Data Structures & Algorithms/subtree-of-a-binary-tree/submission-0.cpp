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
    bool match(TreeNode* a, TreeNode* b){
        if(!a&&!b)return true;
        if(a&&b&&a->val==b->val){
            if(match(a->left,b->left)&& match(a->right,b->right))return true;
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node&&subRoot){
                if(node->val==subRoot->val){
                    if(match(node,subRoot))return true;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }

        return false;
    }
};
