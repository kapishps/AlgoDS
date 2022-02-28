class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return 0;
        }
        long t1 = x, t2 = 0, y = x;
        while(t1){
            t2 *= 10;
            t2 += t1%10;
            t1 /= 10;
        }
        
        return t2 == y;
    }
};