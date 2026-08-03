class Solution {
    int mincost(int ind, int n,vector<int>&cost,vector<int>&dp){
        if(ind==n){
            return 0;
        }
        if(ind>n)return 1e9;
        if(dp[ind]!=-1)return dp[ind];
        int one=cost[ind]+mincost(ind+1,n,cost,dp);
        int two=cost[ind]+mincost(ind+2,n,cost,dp);
        return dp[ind]= min(one,two);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(mincost(0,n,cost,dp),mincost(1,n,cost,dp));
    }
};
