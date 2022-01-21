vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> st;
    vector<int> ans;
    for(int i = 0; i< A.size(); i++){
        if(st.empty()){
            ans.push_back(-1);
            st.push(i);
        } else {
            while(!st.empty()){
                int top = st.top();
                if(A[top] >= A[i]){
                    st.pop();
                } else {
                    break;
                }
            }
            if(st.empty()){
                ans.push_back(-1);
            } else {
                ans.push_back(A[st.top()]);
            }
            st.push(i);
        }
    }
    return ans;
}
