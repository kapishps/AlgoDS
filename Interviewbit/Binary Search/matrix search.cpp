int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // row column naming exchanged;

    int clo = 0, chi = A.size()-1, cmid;
    while(clo < chi){
        cmid = (clo+chi)/2;
        if(A[cmid][A[0].size()-1] < B){
            clo = cmid +1;
        } else {
            chi = cmid;
        }
    }

    int rlo =0, rhi = A[0].size()-1, rmid;
    while(rlo < rhi){
        rmid = (rlo+rhi)/2;
        if(A[clo][rmid] < B){
            rlo = rmid + 1;
        } 
        else {
            rhi = rmid;
        }
    }
    
    return A[clo][rlo] == B;
}