class Solution {
    int bs(int low, int high, int target, vector<int>& nums){
        if(low>high)return -1;
        int mid=(low+high)/2;
        if(nums[mid]==target)return mid;
        if(nums[mid]>target){
            return bs(low,mid-1,target, nums);
        }
        if(nums[mid]<target){
            return bs(mid+1,high,target, nums);
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return bs(0,n-1,target,nums);
    }
};
