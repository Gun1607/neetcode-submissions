class Solution {
    int dfs (int i , int j, vector<vector<int>>&grid, vector<vector<int>>& vis){
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
        int dist=0;
        for(int k=0;k<4;k++){
            int x=i+dir[k].first;
            int y=j+ dir[k].second;
            if(x>=0&& y>=0&&x<grid.size()&&y<grid[0].size()&&grid[x][y]==1&&!vis[x][y]){
                vis[x][y]=1;
                int m=1+dfs(x,y,grid,vis);
                dist+=m;
            }
        }
        return dist;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m= grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&!vis[i][j]){
                    vis[i][j]=1;
                    int m=1+dfs(i,j,grid, vis);
                    if(m>ans)ans=m;
                }
            }
        }
        return ans;
    }
};
