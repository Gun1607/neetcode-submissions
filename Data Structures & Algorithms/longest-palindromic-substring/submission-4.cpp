class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        
        int l=0,r=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]&&((j-i)<=2||dp[i+1][j-1])){
                    dp[i][j]=true;
                    if(r-l<j-i){
                        r=j;
                        l=i;
                    }
                }else{
                    dp[i][j]=false;
                }
            }
        }
        string ans=s.substr(l,r-l+1);
        return ans;
    }
};
