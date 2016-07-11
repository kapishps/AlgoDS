#include <iostream>

using namespace std;

//https://www.hackerearth.com/problem/algorithm/monk-at-the-graph-factory/

int main() {
    int n;
    cin>>n;
    int a,sum=0;
    for (int i = 0; i < n; ++i) {
        cin>>a;
        sum+=a;
    }
    if(sum==2*(n-1))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}