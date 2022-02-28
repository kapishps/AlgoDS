class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        stack<vector<int>> st;
        sort(v.begin(), v.end());
        
        st.push({v[0][0], v[0][1]});
        for(int i =1; i< v.size(); i++){
            vector<int> t = st.top();
            if(t[1] < v[i][0]){
                st.push({v[i][0], v[i][1]});
            } else {
                st.pop();
                st.push({t[0], max(t[1], v[i][1])});
            }
        }
        
        vector<vector<int>> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};