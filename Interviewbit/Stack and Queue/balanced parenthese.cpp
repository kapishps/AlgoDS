int Solution::solve(string A) {
    stack<int> st;
    for(int i =0; i< A.size(); i++){
        int curr = A[i] - '(';
        if(!st.empty() && st.top() == 0 && curr == 1){
            st.pop();
        } else{
            st.push(curr);
        }
    }
    return st.empty();
}
