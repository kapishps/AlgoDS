int solve(int* A, int n1, int B) {
    if(A[n1-1] <= B){
        return n1;
    }
    int lo = 0, hi = n1-1, mid;
    while(lo < hi){
        mid = (lo+hi)/2;
        if(A[mid] <= B){
            lo = mid +1;
        } else{
            hi = mid;
        }
    }
    return lo;
}