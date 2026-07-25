class Solution {
    int maxamnt(int ind, vector<int>& nums,vector<int>&dp){
        if(ind>=nums.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int take=nums[ind]+maxamnt(ind+2, nums,dp);
        int skip=maxamnt(ind+1,nums,dp);
        return dp[ind]= max(take,skip);
    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return maxamnt(0,nums,dp);
    }
};
