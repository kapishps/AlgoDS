class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(int i =0;i<s.size();i++){
            m[s[i]]++;
        }
        vector<pair<int,char>> v;
        for(auto i:m){
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end(), greater<pair<int,char>>());
        string ans;
        for(auto i: v){
            int x = i.first;
            while(x){
                ans += i.second;
                x--;
            }
        }
        return ans;
    }
};