#include <iostream>
#include <set>
using namespace std;

//https://www.hackerearth.com/problem/algorithm/monk-in-the-real-estate/

int main() {
    int t;
    cin>>t;
    while(t--){
        int e;
        cin>>e;
        set <int> s;
        for (int i = 0; i < e; ++i) {
            int a,b;
            cin>>a>>b;
            s.insert(a);
            s.insert(b);
        }
        cout<<s.size()<<endl;
    }
    return 0;
}