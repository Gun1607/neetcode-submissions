class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty())return "";
        int n=strs.size();
        string s;
        for(int i=0;i<n;i++){
            s+= to_string(strs[i].size())+"#"+strs[i];
            
        }
        
        return s;
    }

    vector<string> decode(string s) {
        if(s=="")return {};
        int n=s.size();
        vector<string> ans;
        string str;
        int i=0;
        while(i<n){
            int j=i;
            while(s[j]!='#')j++;
            int len=stoi(s.substr(i,j-i));
            ans.push_back(s.substr(j+1,len));
            i=j+1+len;
        }
        return ans;
    }
};
