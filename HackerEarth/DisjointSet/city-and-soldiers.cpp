#include <iostream>
using namespace std;
int parent[100001];

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    x = findset(x), y = findset(y);
    parent[x]=y;
}

//https://www.hackerearth.com/problem/algorithm/city-and-soldiers/

int main(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<=n;i++) {
        parent[i] = i;
    }
    for (int i = 0; i < q; ++i) {
        int o;
        cin>>o;
        if(o==1){
            int a,b;
            cin>>a>>b;
            unionset(a,b);
        }
        else if(o==2){
            int a;
            cin>>a;
            int b=findset(a);
            parent[a]=a;
            parent[b]=a;
        }
        else{
            int a;
            cin>>a;
            cout<<findset(a)<<endl;
        }
    }
    return 0;
}