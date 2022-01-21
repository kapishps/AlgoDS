int Solution::searchInsert(vector<int> &A, int B) {
    int lo =0, hi = A.size(), mid;
    while(lo < hi){
        mid = (hi+lo)/2;
        if(A[mid] < B){
            lo = mid +1;
        } else {
            hi = mid;
        }
    }
    return lo;
}
