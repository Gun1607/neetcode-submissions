class Solution {
    void dfs(int node,vector<vector<pair<int,int>>>&adj,  vector<int>&s){
        
        int n=adj[node].size();
        
        //bool flag=false;
        for(int i=0;i<n;i++){
            if(adj[node][i].second>0){
                
                
                adj[node][i].second=0;
                dfs(adj[node][i].first, adj, s);
                
                
            }
        }
        s.push_back(node);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,int>mp;
        unordered_map<int,string>rmp;
        int n=tickets.size();
        for(int i=0;i<n;i++){
            string a=tickets[i][0];
            string b=tickets[i][1];
            if(mp.find(a)==mp.end())mp[a]=1;
            if(mp.find(b)==mp.end())mp[b]=1;
        }
        int k=0;
        for(auto &[key,val]: mp){
            mp[key]=k;
            rmp[k]=key;
            k++;
        }
        int p=mp.size();
        vector<vector<pair<int,int>>>adj(p);
        for(int i=0;i<n;i++){
            int a=mp[tickets[i][0]];
            int b=mp[tickets[i][1]];
            adj[a].push_back({b,1});
        }
        for(int i=0;i<p;i++){
            if(!adj[i].empty())
            sort(adj[i].begin(),adj[i].end());
        }
        vector<vector<int>>ans;
        vector<int>s={};
        dfs(mp["JFK"],adj,s);
        reverse(s.begin(),s.end());
        vector<string>a;
        
        for(int i=0;i<s.size();i++){
            
            a.push_back(rmp[s[i]]);
        }
        return a;
    }
};
