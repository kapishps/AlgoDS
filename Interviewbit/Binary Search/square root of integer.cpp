int Solution::sqrt(int A) {
    if(A < 2) return A;
    int lo = 0, hi = A, mid, ans = 0;
    while(lo < hi){
        mid = (lo+hi)/2;
        if(mid <= (A/mid)){
            ans = mid;
            lo = mid +1;
        } else {
            hi = mid;
        }
    }
    return ans;
}
