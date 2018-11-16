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
const int MAXN = 2e5+9;

struct cust{
    string name;
    int cibil;
    int risk;
    int index;

    cust(string name, int cibil, int risk, int index){
        this->name = name;
        this->cibil = cibil;
        this->risk = risk;
        this->index = index;
    }
    cust(){}
};

bool prioritize (cust p1 ,cust p2){
    if (p1.cibil == p2.cibil){
        if(p1.risk == p2.risk){
            if(p1.name == p2.name){
                return p1.index < p2.index;
            } else
                return p1.name > p2.name;
        } else
            return p1.risk < p2.risk;
    } else
        return p1.cibil > p2.cibil;
}



int main() {
    FastIO;
    int t;
    cin>>t;
    while (t--){
        int n,k;
        cin>>n;
        struct cust customers[n];
        for (int i = 0; i < n; ++i) {
            string name;
            int cibil,risk;
            cin>>name>>cibil>>risk;
            customers[i] = cust(name, cibil, risk, i);
        }
        cin>>k;
        sort(customers, customers+n, prioritize);
        cout<<customers[k-1].name<<" "<<customers[k-1].cibil<<" "<<customers[k-1].risk;
        cout<<"\n";
    }
    return ;
}