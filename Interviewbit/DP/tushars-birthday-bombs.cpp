vector<int> Solution::solve(int A, vector<int> &B) {
    vector<pair<int, int> > v;
    vector<int> ans;
    int mini = INT_MAX, max_kicks = 0;

    for (int i = 0; i < B.size(); i++) {
        if (B[i] < mini) {
            v.push_back(make_pair(B[i], i));
            mini = B[i];
        }
    }
    if (A <= 0 || mini > A)
        return ans;
    max_kicks = A / mini;

    int sum = max_kicks * mini;
    for (int i = 0; i < v.size() ; i++) {
        while(A >= sum-mini+v[i].first && ans.size() < max_kicks) {
            ans.push_back(v[i].second);
            sum-= mini;
            sum+=v[i].first;
        }
    }

    return ans;
}