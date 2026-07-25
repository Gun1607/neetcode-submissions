class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int r=0;
        for(int i=0;i<n;i++){
            r=max(r,piles[i]);
        }
        int l=1;
        while(l<=r){
            int mid=(l+r)/2;
            int hrs=0;
            for(int i=0;i<n;i++){
                if(piles[i]%mid!=0)
                hrs+=piles[i]/mid+1;
                else hrs+=piles[i]/mid;
            }
            
            if(hrs>h){
                l=mid+1;
            }else if(hrs<=h)r=mid-1;
        }
        return l;
    }
};
