class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>maxi)maxi=mp[nums[i]];
        }
        vector<vector<int>>bucket(maxi+1);
        for(auto it:mp){
            bucket[(it).second].push_back((it).first);
        }
        vector<int>ans;
        int cnt=k;
        for(int i=maxi;i>=0;i--){
            if(bucket[i].size()<cnt){
                for(int j=0;j<bucket[i].size();j++){
                    ans.push_back(bucket[i][j]);
                }
                cnt-=bucket[i].size();
            }
            else{
                int j=0;
                while(cnt>0){
                    ans.push_back(bucket[i][j]);
                    j++;
                    cnt--;
                }
                
            }
            if(cnt==0)break;
        }
        return ans;
    }
};
