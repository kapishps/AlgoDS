// Time complexity:- O(n*k*log(k)) solution instead of nomal sort ie O(n*k*log(n*k))
// Space complexity :- O(n*k)
vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int> ans;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    map<int,int> m;

    for(int i =0 ;i < A.size(); i++){
        pq.push({A[i][0],i});
        m[i]++;
    }
    while(!pq.empty()){
        pair<int,int> top = pq.top();
        pq.pop();
        ans.push_back(top.first);
        if(m[top.second] < A[top.second].size()){
            pq.push({A[top.second][m[top.second]], top.second});
            m[top.second]++;
        }
    }
    return ans;
}
