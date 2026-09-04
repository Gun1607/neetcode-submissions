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
    int pre=0;
    map<int,int> mp;
     TreeNode* build( int ina,int inb,vector<int>& preorder, vector<int>& inorder){
        if(ina>inb)return NULL;
        if(ina==inb){
            TreeNode* node= new TreeNode(inorder[ina]);
            pre++;
            return node;
        }
        TreeNode* node= new TreeNode(preorder[pre]);
        int x=pre;
        pre++;

        node->left=build(ina,mp[preorder[x]]-1,preorder,inorder);
        node->right=build(mp[preorder[x]]+1,inb,preorder,inorder);
        return node;

     }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(0,inorder.size()-1, preorder,inorder);

    }
};
