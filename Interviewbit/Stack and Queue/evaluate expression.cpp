int Solution::evalRPN(vector<string> &A) {
    stack<int> st;
    for(int i =0; i< A.size(); i++){
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/"){
            int r = st.top();
            st.pop();
            int l = st.top();
            st.pop();
            if(A[i] == "+"){
                st.push(l + r);
            }
            if(A[i] == "-"){
                st.push(l - r);
            }
            if(A[i] == "*"){
                st.push(l * r);
            }
            if(A[i] == "/"){
                st.push(l / r);
            }
        } else {
            st.push(stoi(A[i]));
        }
    }
    return st.top();
}