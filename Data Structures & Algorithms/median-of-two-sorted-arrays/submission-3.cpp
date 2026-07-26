class Solution {
    double median(vector<int>&nums1, vector<int>&nums2, int n,int m){
        
        int med=(n+m)/2;
        int low=0,high=nums1.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            int n2=med-mid-1;
            if(nums1[mid]<=nums2[n2]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        int k=med-low;
        if((n+m)%2==0){
            int nth;
            if(low>=n)nth=nums2[k];
            else if(k>=m)nth=nums1[low];
            else nth=min(nums1[low],nums2[k]);
            int nmth;
            if(low-1<0)nmth=nums2[k-1];
            else if(k-1<0)nmth=nums1[low-1];
            else nmth=max(nums1[low-1],nums2[k-1]);
            return (double)(nth+nmth)/2;
        }
        return min(nums1[low],nums2[k]);
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n==0){
            if(m%2==0)return (double)(nums2[m/2]+nums2[m/2-1])/2;
            else return nums2[m/2];
        }
        if(m==0){
            if(n%2==0)return (double)(nums1[n/2]+nums1[n/2-1])/2;
            else return nums1[n/2];
        }
        if(n<m)return median(nums1,nums2,n,m);
        return median(nums2,nums1,m,n);

    }
};
