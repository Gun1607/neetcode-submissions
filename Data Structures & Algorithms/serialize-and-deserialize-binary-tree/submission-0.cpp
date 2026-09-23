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

class Codec {
public:
    void traverse(TreeNode* node, string & s){
        if(node==NULL){
            
            s.push_back('N');
            s.push_back(',');
            return;
        }
        
        s+=to_string(node->val);
        s.push_back(',');
        traverse(node->left,s);
        traverse(node->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        traverse(root,s);
        s.pop_back();
        cout<<s<<endl;
        return s;
    }

    vector<string> split(const string &s, char delim){
        vector<string>ele;
        stringstream ss(s);
        string item;
        while(getline(ss,item,delim)){
            ele.push_back(item);
        }
        return ele;
    }
    TreeNode* des(vector<string>& vals, int &i){
        if(vals[i]=="N"){
            i++;
            return NULL;
        }
        TreeNode* node= new TreeNode(stoi(vals[i]));
        i++;
        node->left=des(vals, i);
        node->right=des(vals,i);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s.empty())return NULL;
        vector<string>vals=split(s,',');
        int i=0;
        return des(vals, i);
    }
};
