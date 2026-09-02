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
    int count=0;
    //vector<int>ans;
    void gnodes(TreeNode* node, int last){
        if(node==NULL)return;
        if(node->val>=last){
            count++;
            //ans.push_back(node->val);
            last=node->val;
        }
        gnodes(node->left,last);
        gnodes(node->right,last);

    }
public:
    int goodNodes(TreeNode* root) {
        gnodes(root,-110);
       // for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        return count;
    }
};
