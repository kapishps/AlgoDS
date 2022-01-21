vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    queue<int> q;
    map<int,int> m;
    vector<int> v;
    for(int i =0; i< A.size(); i++){
        m[A[i]]++;
        if(i+1 >= B) {
            if(i-B >= 0){
                m[A[i-B]]--;
            }
            if(m[A[i-B]] == 0){
                m.erase(A[i-B]);
            }
            v.push_back(m.rbegin()->first);
        }
    }
    return v;
}
