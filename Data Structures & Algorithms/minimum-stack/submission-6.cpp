class MinStack {
    long long min;
    stack<long long>st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            min=val;
            st.push(0);
        }else{
            long long k=val-min;
            st.push(k);
            if(val<min){
                min=val;
            }
        }
    }
    
    void pop() {
        long long k=st.top();
        if(st.top()<0){
            min=min-k;
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<0)return min;
        long long x=st.top()+min;
        return x;
    }
    
    int getMin() {
        return min;
    }
};
