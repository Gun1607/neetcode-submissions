class DS{
    vector<int>par;
    vector<int>size;
public:
    DS(int n){
        par.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    int findpar(int ind){
        if(par[ind]==ind)return ind;
        return par[ind]=findpar(par[ind]);
    }

    void unionsize(int a,int b){
        int ula=findpar(a);
        int ulb=findpar(b);
        if(ula==ulb)return;
        if(size[ula]>size[ulb]){
            size[ula]+=size[ulb];
            par[ulb]=ula;
        }else{
            size[ulb]+=size[ula];
            par[ula]=ulb;
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int xi=points[i][0];
                int yi=points[i][1];
                int xj=points[j][0];
                int yj=points[j][1];
                int wt=abs(xi-xj)+abs(yi-yj);
                pq.push({wt,i,j});
            }
        }
        DS ds(n);
        int ans=0;
        while(!pq.empty()){
            auto edge=pq.top();
            pq.pop();
            int wt=edge[0];
            int a=edge[1];
            int b=edge[2];
            if(ds.findpar(a)==ds.findpar(b))continue;
            ans+=wt;
            ds.unionsize(a,b);
        }
        return ans;
    }
};
