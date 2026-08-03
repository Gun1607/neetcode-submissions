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
        vector<int>dp(n+1,-1);
        int nnext=1;
        int next=1;
        for(int i=n-2;i>=0;i--){
            int x=nnext+next;
            nnext=next;
            next=x;
        }
        return next;
    }
};
