#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

int parent[MAXN],rnk[MAXN];

int findset(int x) {
    if (x == parent[x])
        return x;
    parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x,int y) {
    int px = findset(x);
    int py = findset(y);
    if (px != py) {
        if (rnk[px] > rnk[py]) {
            swap(px, py);
        }
        rnk[py] += rnk[px];
        parent[px] = py;
    }
}

void initialiseset(int start,int end) {
    for (int i = start; i <= end; ++i) {
        parent[i] = i;
        rnk[i] = 1;
    }
}

struct compare{                     //Specific to this question
    bool operator()(const pair<int, pii> &p1, const pair<int, pii> &p2){
        if(p1.first==p2.first){
            return ((p1.first+p1.second.first+p1.second.second) <
                    (p2.first+p2.second.first+p2.second.second));
        }
        return (p1.first < p2.first);
    }
};

int kruskal(vector<pair<int, pii> > edgelist) {
    int mst_weight = 0;
    sort(edgelist.begin(), edgelist.end(),compare());
    for (auto i:edgelist) {
        if (findset(i.second.first) != findset(i.second.second)) {
            unionset(i.second.first, i.second.second);
            mst_weight += i.first;
        }
    }
    return mst_weight;
}


int main() {
    Boost;
    int n,m;
    cin>>n>>m;
    vector<pair<int, pii> > edgelist;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        edgelist.push_back(mp(w,mp(x,y)));
    }
    initialiseset(1,n);
    cout<<kruskal(edgelist);
    return 0;
}
