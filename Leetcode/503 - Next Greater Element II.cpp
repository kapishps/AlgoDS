class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> st;
        int n = nums.size();
        for(int i = (2*n) -1; i >= 0; i--){
            while(!st.empty()){
                int t = st.top();
                if(nums[t] <= nums[i%n]){
                    st.pop();
                } else {
                    break;
                }
            }
            
            if(st.empty()){
                ans[i%n] = -1;
            } else {
                ans[i%n] = st.top();
            }
            st.push(i%n);
        }
        
        for(int i =0; i<n;i++){
            if(ans[i] != -1){
                ans[i] = nums[ans[i]];
            }
        }
        return ans;
    }
};