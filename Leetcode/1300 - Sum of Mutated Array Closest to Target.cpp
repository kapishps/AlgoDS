class Solution {
public:
    int util(vector<int>& arr, int mid, int target){
        int ans = 0;
        for(int i =0; i< arr.size(); i++){
            if(arr[i] > mid){
                ans += mid;
            } else {
                ans += arr[i];
            }
        }
        return abs(ans - target);
    }
    
    int findBestValue(vector<int>& arr, int target) {
        int lo =0, hi = 100001;
        while(lo < hi){
            int mid = (lo+hi)/2;
            
            int a = util(arr, mid, target);
            int b = util(arr, mid+1, target);
            
            if(a > b){
                lo = mid +1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};