class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return 0;
        }
        map<char, int> m1,m2;
        for(int i =0; i< s.size(); i++){
            m1[s[i]]++;
        }
        for(int i =0; i< t.size(); i++){
            m2[t[i]]++;
        }
        for(auto i: m1){
            if(i.second != m2[i.first]){
                return 0;
            }
        }
        return 1;
    }
};