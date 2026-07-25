class MinStack {
    long long topp;

    vector<long long>arr;
    vector<long long>mini;
    long long min;
public:
    MinStack() {
        min=-1;
        topp=-1;
    }
    
    void push(int val) {
        topp++;
        if(min==-1||mini[min]>=val){
            min++;
            mini.push_back(val);
        }
        arr.push_back(val);
    }
    
    void pop() {
        int x=arr[topp];
        if(x==mini[min]){
            mini.pop_back();
            min--;
        }
        arr.pop_back();
        topp--;
    }
    
    int top() {
        if(topp==-1)return -1;
        return arr[topp];
    }
    
    int getMin() {
        return mini[min];
    }
};
