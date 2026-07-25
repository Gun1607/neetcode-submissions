class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>cars;
        int n=speed.size();
        for(int i=0;i<n;i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end());
        int ans=1;
        double time=(target-cars[n-1].first)/((double)cars[n-1].second);
        for(int i=n-2;i>=0;i--){
            double t=(double)(target-cars[i].first)/cars[i].second;
            if(t>time){
                ans++;
                time=t;
            }
        }
        return ans;
    }
};
