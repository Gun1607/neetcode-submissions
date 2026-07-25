class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int h=m*n-1;
        int l=0;
        while(l<=h){
            int mid=(l+h)/2;
            int a=mid/n;
            int b=mid%n;
            if(target==matrix[a][b])return true;
            if(target>matrix[a][b]){
                l=mid+1;
            }else if(target<matrix[a][b]){
                h=mid-1;
            }
        }
        return false;
    }
};
