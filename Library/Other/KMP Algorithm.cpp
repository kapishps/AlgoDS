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

void kmpPreprocess(string P,int b[],int m) {
    int i = 0, j = -1;
    b[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j])
            j = b[j]; // if different, reset j using b
        i++;
        j++; // if same, advance both pointers
        b[i] = j;
    }
}

void kmpSearch(string T,string P,int n, int m) {
    int b[MAXN] = {0};
    kmpPreprocess(P,b,m);
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && T[i] != P[j])
            j = b[j];
        i++;
        j++;
        if (j == m) { // a match found when j == m
            cout << "P is found at index " << i - j << " in T\n";
            j = b[j]; // prepare j for the next possible match
        }
    }
}

/*
abcxabcdabcdabcy
abcdabcy

8
 */

int main() {
//    Boost;
    string T,P;
    cin>>T>>P;
    kmpSearch(T,P,T.size(),P.size());
    return 0;
}
