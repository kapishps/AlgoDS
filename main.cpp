#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <time.h>

using namespace std;

const int MOD=1e9+7;
const int MAXN=1e6+1;

int main() {
//    clock_t tStart = clock();
    int x,n;
    cin>>x>>n;
    int count=0;
//    int i=x;
    for(int i=1;i<=x;i++){
        int t=i+1;
        int a=0,b=0;
        while(t){
            a++;
            t=(t/10);
        }
        t=(2*i)+1;
        while(t){
            b++;
            t=(t/10);
        }
        if(a!=b)
            count++;
    }
//    cout<<a<<" "<<b;
    cout<<count;
//    cout<<endl;
//    cout<<(double)(clock() - tStart)/CLOCKS_PER_SEC;
    return 0;
}
