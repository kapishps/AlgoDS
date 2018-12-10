#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define present(m,v) (m.find(v)!=m.end())

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

map<set<int>,pii> m;


void printarrange(set<int> k){
    cout<<"?";
    for(auto i: k){
        cout<<" "<<i;
    }
    cout<<"\n";
    fflush(stdout);
    return;
}


int solveforsix(set<int> idxs) {
    m.clear();
    int x, y;

    for (auto i : idxs) {
        set<int> k;
        for (auto j : idxs) {
            if (i != j)
                k.insert(j);
        }

        printarrange(k);
        cin >> x >> y;

        pii v;
        v.first = x;
        v.second = y;
        m[k] = v;
    }

    x = -1;
    y = -1;
    int z = -1;
    map<int,int> vis;
    for (auto i: m) {
        vis[i.second.second]++;
    }

    for(auto i: vis){
        if(z == -1){
            z = i.first;
        } else{
            y = i.first;
        }
        if(vis[z] < i.second) {
            y = z;
            z = i.first;
        }
    }

    for (auto i: m) {
        if(i.second.second == y)
            x = i.second.first;
    }

//    cerr<<x<<y<<z;

    vis[x]++;
    vis[y]++;
    vis[z]++;

    for(auto i: m){
        if(i.second.first == x && i.second.second == y && i.first.find(z) != i.first.end()){
            for(auto j : i.first){
                vis[j]++;
            }
        }
    }

    for(auto i: idxs){
//        cerr<<i<<" ";
        if(vis[i] == 0)
            return i;
    }
    return 0;
}


int main() {
//    FastIO;
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        set<int> curr;
        for (int i = 1; i <=5; ++i) {
            curr.insert(i);
        }

        if(n%2==0){
            int x,y;
            for(int i = 6; i < n;i += 2) {
                printarrange(curr);
                cin>>x>>y;
                curr.erase(x);
                curr.erase(y);
                curr.insert(i);
                curr.insert(i+1);
            }
            curr.insert(n);
        }
        else{
            int x,y;
            for(int i = 6; i < n-1;i+= 2) {
                printarrange(curr);
                cin>>x>>y;
                curr.erase(x);
                curr.erase(y);
                curr.insert(i);
                curr.insert(i+1);
            }
            printarrange(curr);
            cin>>x>>y;
            curr.erase(x);
            curr.insert(n-1);
            curr.insert(n);
        }

        int ans = solveforsix(curr);
        cout<<"! "<<ans<<"\n";
        fflush(stdout);
    }
    return 0;
}

//1
//6
//4 5
//4 5
//4 5
//3 5
//3 4
//3 4


//1
//6
//5 2
//5 1
//5 2
//2 1
//2 1
//2 1
