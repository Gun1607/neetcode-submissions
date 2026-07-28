class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<m;i++){
            adj[times[i][0]].push_back({times[i][2],times[i][1]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int> vis(n+1,0);
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node])continue;
            vis[node]=1;
            
            for(int i=0;i<adj[node].size();i++){
                int noded=adj[node][i].first;
                int nodeb=adj[node][i].second;
                if(dis+noded<dist[nodeb]){
                    dist[nodeb]=dis+noded;
                    pq.push({dist[nodeb],nodeb});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        if(ans==1e9)return -1;
        return ans;
    }
};
