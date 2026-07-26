class Solution {
    int bs(vector<int>&nums,int target, int low,int high){
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                low=mid+1;
            }else high=mid-1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int min=-1;
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]<nums[high]){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        int s1=high,a,b;
        if(target>nums[nums.size()-1])
        return bs(nums,target, 0,s1-1);
        else
        return bs(nums,target, s1,nums.size()-1);
        return -1;
    }
};
