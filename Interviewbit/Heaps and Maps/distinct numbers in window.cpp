vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int,int> m;
    vector<int> ans;

    for(int i = 0; i < A.size(); i++){
        m[A[i]]++;
        if(i >= B) {
            if(m[A[i-B]] == 1){
                m.erase(A[i-B]);
            } else {
                m[A[i-B]]--;
            }
        }
        if(i >= B -1){ // considering 1st window
            ans.push_back(m.size());
        }
    }
    return ans;
}
