class Solution {
public:
    int canCompleteCircuit(vector<int>& A, vector<int>& B) {
        int sum = 0, ans =0, curr = 0;
        for(int i =0; i< A.size(); i++){
            sum += A[i]-B[i];
            curr += A[i]-B[i];
            if(curr < 0){
                ans = i+1;
                curr = 0;
            }
        }
        if(sum < 0){
            return -1;
        }
        return ans;
    }
};