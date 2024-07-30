class Solution {
public: 
    long solve(int a , int b , char op){
        if(op == '+') return a+b;
        else if(op == '-') return a-b;
        else if(op == '*') return (long)a*b;
        else return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<long>st;
        int n = tokens.size();
        for(int i = 0; i < n; i++){
            if(tokens[i].size() == 1 and tokens[i][0] < 48){
                long integer2 = st.top();
                st.pop();
                long integer1 = st.top();
                st.pop();
                string Operator = tokens[i];
                long ans = solve(integer1 , integer2 , Operator[0]);
                st.push(ans);
            }
            else{
                st.push(stol(tokens[i]));
            }
        }
        return st.top();
    }
};