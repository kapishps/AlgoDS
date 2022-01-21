int Solution::solve(vector<int> &A, int B) {
    int lo = 0, hi = 2000009, mid, ans = 0;
    while(lo < hi){
        mid = (lo+hi)/2;
        int wood = 0;
        for(int i =0; i<A.size();i++){
            if(A[i] >= mid){
                wood += A[i]-mid;
            }
        }
        if(wood >= B){
            ans = max(ans, mid);
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return ans;
}