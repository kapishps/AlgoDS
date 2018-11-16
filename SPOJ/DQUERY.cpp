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
const int MAXN = 1e6+9;

int occs[MAXN], BIT[30005], n, ans[200005];

typedef struct node{
    int s, e, val, pos;
    bool operator<(const node& n) const{
        if(e != n.e)
            return e < n.e;
        return val > n.val;
    }
    node(){};
    node(int ss, int ee, int v, int p){
        s = ss, e = ee, val = v, pos = p;
    }
} node;

void update(int x, int val) {   //assigns value val to a[x]
    while(x <= n){
        BIT[x] += val;
        x += x & -x;
    }
}

int query(int x) {              //calculate the sum of all a[i] such that 0 <= i < x
    int sum = 0;
    while(x > 0){
        sum += BIT[x];
        x -= x & -x;
    }
    return sum;
}

// https://www.spoj.com/problems/DQUERY/

int main() {
    FastIO;
    int q, s, e;
    vector<node> v;             //vector to store both input array and queries

    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>s;
        v.push_back(node(i, i, s, -1));
    }

    cin>>q;
    for(int i = 0; i < q; i++){
        cin>>s>>e;
        v.push_back(node(s, e, 0, i));
    }

    sort(v.begin(), v.end());

    for(int i = 0;i < v.size(); i++){
        if(v[i].val == 0){
            ans[v[i].pos] = query(v[i].e) - query(v[i].s - 1);
        }
        else{
            if(occs[v[i].val] != 0)
                update(occs[v[i].val], -1);
            update(v[i].s, 1);
            occs[v[i].val] = v[i].s;
        }
    }


    for(int i = 0; i < q; i++){
        cout<<ans[i]<<"\n";
    }

}