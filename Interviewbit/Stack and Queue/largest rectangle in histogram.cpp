int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> st1,st2;
    vector<int> l,r;
    for(int i =0; i<A.size(); i++){
        if(st1.empty()){
            st1.push(i);
            l.push_back(-1);
        } else {
            while(!st1.empty()){
                int top = st1.top();
                if(A[top] >= A[i]) {
                    st1.pop();
                } else {
                    break;
                }
            }
            if(st1.empty()){
                l.push_back(-1);
            } else {
                l.push_back(st1.top());
            }
            st1.push(i);
        }
    }

    for(int i = A.size()-1; i>=0; i--){
        if(st2.empty()){
            st2.push(i);
            r.push_back(A.size());
        } else {
            while(!st2.empty()){
                int top = st2.top();
                if(A[top] >= A[i]) {
                    st2.pop();
                } else {
                    break;
                }
            }
            if(st2.empty()){
                r.push_back(A.size());
            } else {
                r.push_back(st2.top());
            }
            st2.push(i);
        }
    }
    reverse(r.begin(), r.end());

    int ans = A[0];
    for(int i =0; i<A.size(); i++){
        ans = max(ans, (r[i]-l[i]-1)*A[i]);
    }
    return ans;
}
