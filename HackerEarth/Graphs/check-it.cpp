#include <iostream>
#include <vector>
#include <set>

using namespace std;

//https://www.hackerearth.com/problem/algorithm/check-it/

int main() {
    int t;
    cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int> > edgelist;
        for (int i = 0; i < m; ++i) {
            int a,b;
            cin>>a>>b;
            a--;b--;
            edgelist.push_back(make_pair(a,b));
        }
        set <int> s;
        for (int i = 0; i < n - 1; ++i) {
            int a;
            cin>>a;
            a--;
            s.insert(edgelist[a].first);
            s.insert(edgelist[a].second);
        }
        if(s.size()==n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}