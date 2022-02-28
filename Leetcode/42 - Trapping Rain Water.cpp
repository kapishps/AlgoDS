class Solution {
public:
    int trap(vector<int>& height) {
        int mx = height[0], n = height.size();
        vector<int> l(n),r(n);
        for(int i =0; i< n; i++){
            mx = max(mx, height[i]);
            l[i] = mx;
        }
        mx = height[n-1];
        for(int i = n-1; i>= 0; i--){
            mx = max(mx, height[i]);
            r[i] = mx;
        }
        
        int ans =0;
        for(int i =0; i< n; i++){
            ans += max(0, min(l[i], r[i]) - height[i]);
        }
        return ans;
    }
};