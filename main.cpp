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

bool isodd(int n){
    return n%2;
}

bool iseven(int n){
    return !isodd(n);
}

void solve(int a[],int n){
    int i=0,j=1;
    while (i<n && j<n){
        if(isodd(a[i]) && iseven(a[j])){
            i+=2;
            j+=2;
        }
        else if(isodd(a[j]) && iseven(a[i])){
            swap(a[i],a[j]);
            i+=2;
            j+=2;
        }
        else{
            if(iseven(a[i])){
                swap(a[i],a[j]);
                j+=1;
            }
            else{
                swap(a[i],a[j]);
                i+=1;
            }
        }
//        cout<<"j";
    }
}

void solution(int a[],int n){
    int even =0,odd =1;
    while(even < n && odd < n){
        while(a[even]%2==0)
            even += 2;
            while (a[odd] % 2 == 1)
                odd += 2;

            if (even !=n-1 || odd != n-1)
                swap(a[even], a[odd]);
        }
    }

void arrangeArray (int a[], int size)
{
    int oddInd = 1;
    int evenInd = 0;
    while (true)
    {
        while (evenInd < size && a[evenInd]%2 == 0)
            evenInd += 2;
        while (oddInd < size && a[oddInd]%2 == 1)
            oddInd += 2;
        if (evenInd < size && oddInd < size)
            swap (a[evenInd], a[oddInd]);
        else
            break;
    }

}



int main() {
//    Boost;
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    arrangeArray(a,n);
    for (int j = 0; j < n; ++j) {
        cout<<a[j]<<" ";
    }
    return 0;
}
