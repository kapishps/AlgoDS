class Solution {
public:
    bool util(string s){
        for(int i =0 ; i< s.size();i++){
            int j = s.size() -1 -i;
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
    
    
    bool validPalindrome(string s) {
        for(int i =0 ; i< (s.size()/2);i++){
            int j = s.size() -1 -i;
            if(s[i] != s[j]){
                return util(s.substr(i+1, j - i)) || util(s.substr(i, j - i));
            }
        }
        return true;
    }
};
