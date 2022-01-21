vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int lo = 0, hi = A.size()-1, mid;
    vector<int> ans;
    while(lo < hi){
        mid = (lo+hi)/2;
        if(A[mid] < B){
            lo = mid +1;
        } else {
            hi = mid;
        }
    }
    if(A[lo] != B){
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    ans.push_back(lo);
    lo = 0, hi = A.size();
    while(lo < hi){
        mid = (lo+hi)/2;
        if(A[mid] <= B){
            lo = mid +1;
        } else {
            hi = mid;
        }
    }
    ans.push_back(lo-1);
    return ans;
}
