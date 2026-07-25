class Solution {
    int mincost(int ind,  int sum, vector<int>& cost ){
        if(ind==cost.size())return sum;
        if(ind>cost.size())return INT_MAX;
        int one=mincost(ind+1, sum+cost[ind], cost);
        int two = mincost(ind+2,sum+cost[ind],cost);
        return min(one,two);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(mincost(0,0,cost),mincost(1,0,cost));
    }
};
