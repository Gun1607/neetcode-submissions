class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int>rt(n),lf(n);
        stack<pair<int,int>>st;
        
        for(int i=n-1;i>=0;i--){            
                while(!st.empty()&&st.top().first>=h[i]){
                    st.pop();
                }
                if(st.empty()){
                rt[i]=h[i]*(n-i);
                
                }
                else rt[i]=h[i]*(st.top().second-i);
                st.push({h[i],i});
        }
        while(!st.empty())st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty()&&st.top().first>=h[i]){
                st.pop();
            }
            if(st.empty()){
                lf[i]=h[i]*(i+1);
            }else{
                lf[i]=h[i]*(i-st.top().second);
            }
            st.push({h[i],i});
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans, lf[i]+rt[i]-h[i]);
        }
        return ans;
    }
};
