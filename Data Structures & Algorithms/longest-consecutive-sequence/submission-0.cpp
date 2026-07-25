class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st(nums.begin(),nums.end());
        int length=0,res=0;
        for(int i=0;i<n;i++){
            if(st.find(nums[i]-1)==st.end()){
                length=1;
                while(st.count(nums[i]+length)){
                    length++;
                }
                res=max(res,length);
            }
        }
        return res;
        
    }
};
