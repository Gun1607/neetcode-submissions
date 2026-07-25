class Solution {
    bool isana(string a,string b){
        if(a.size()!=b.size())return false;
        map<char, int>ma,mb;
        for(int i=0; i<a.size();i++){
            ma[a[i]]++;
            mb[b[i]]++;
           
        }
        for(int i=0;i<a.size();i++){
            if(ma[a[i]]!=mb[b[i]])return false;
        }
        return true;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        //ans.push_back({strs[0]});
        map<string,vector<string>>res;
        for(int i=0;i<strs.size();i++){
            vector<int>count(26,0);
            string key;
            for(int j=0;j<strs[i].size();j++){
                count[strs[i][j]-'a']++;
            }
            key=to_string(count[0]);
            for(int i=1;i<26;i++){
                key+=','+to_string(count[i]);
            }
            res[key].push_back(strs[i]);
        }
        for(auto it=res.begin();it!=res.end();it++){
            ans.push_back((*it).second);
        }
        return ans;
    }
};
