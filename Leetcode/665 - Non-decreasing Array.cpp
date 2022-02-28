class Solution {
public:
    bool util(int a, int b, int c, int d){
        if(a <= b && b <= c && c <= d){
            return true;
        }
        return false;
    }
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for(int i = 1; i< nums.size(); i++){
            if(nums[i-1] > nums[i]){
                if(cnt > 0){
                    return false;
                }
                cnt++;
                if(i-2 >= 0 && i+1 < nums.size()){
                    if(!util(nums[i-2], nums[i], nums[i], nums[i+1]) && !util(nums[i-2], nums[i-1], nums[i-1], nums[i+1])){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};