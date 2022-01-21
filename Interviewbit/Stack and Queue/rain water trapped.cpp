int Solution::trap(const vector<int> &A) {
    vector<int> l;
    int mx = 0, ans = 0;
    for(int i =0; i< A.size(); i++){
        mx = max(mx, A[i]);
        l.push_back(mx);
    } 
    mx = 0;
    for(int i =A.size()-1; i>= 0; i--){
        mx = max(mx, A[i]);
        ans += max(0, min(l[i], mx) - A[i]);
    }
    return ans;
}