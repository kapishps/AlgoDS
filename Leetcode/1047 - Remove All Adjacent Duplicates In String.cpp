class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty()){
                st.push(s[i]);
            } else {
                char t = st.top();
                if(t == s[i]){
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }
        
        string ans;
        while(!st.empty()){
            char t = st.top();
            st.pop();
            ans += t;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};