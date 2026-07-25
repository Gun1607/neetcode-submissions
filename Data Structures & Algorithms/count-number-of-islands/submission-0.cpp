class Solution {
    void dfs(int i,int j, vector<vector<char>>&grid, vector<vector<int>>&vis){
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        for(int k=0;k<4;k++){
            int a=i+dir[k].first;
            int b=j+dir[k].second;
            if(a>=0&&b>=0&&a<grid.size()&&b<grid[0].size()&&!vis[a][b]&&grid[a][b]=='1'){
                vis[a][b]=1;
                dfs(a,b,grid,vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    vis[i][j]=1;
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
