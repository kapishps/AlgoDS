class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty()){
                st.push({s[i], 1});
            } else {
                pair<char,int> t = st.top();
                if(t.first == s[i]){
                    if(t.second == k-1){
                        st.pop();
                    } else {
                        int x = t.second;
                        st.pop();
                        st.push({s[i], x+1});
                    }
                } else {
                    st.push({s[i], 1});
                }
            }
        }
        
        string ans;
        while(!st.empty()){
            pair<char,int> t = st.top();
            st.pop();
            for(int i =0; i< t.second; i++){
                ans += t.first;
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};