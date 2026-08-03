class Solution {
    int dp(int n, int ind,vector<int>&dpa){
        if(n==ind){
            return  1;
        }
        if(n<ind){
            return 0;
        }
        if(dpa[ind]!=-1)return dpa[ind];
        int one=dp(n,ind+1,dpa);
        int two=dp(n,ind+2,dpa);
        return dpa[ind]= one+two;
    }
public:
    int climbStairs(int n) {
        vector<int>dpa(n+1,-1);
        return dp(n,0,dpa);
    }
};
