class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int a=0,b=0;
                if(!st.empty()){
                    a=st.top();
                    st.pop();
                }
                if(!st.empty()){
                    b=st.top();
                    st.pop();
                }
                if(tokens[i]=="+"){
                    st.push(a+b);
                }
                else if(tokens[i]=="-")st.push(b-a);
                else if(tokens[i]=="*")st.push(a*b);
                else if(tokens[i]=="/"&&a!=0)st.push(b/a);
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
