#include <iostream>
#include <cmath>

using namespace std;
int ans[1000001]={0};

void sieve(){
    bool prime[1001];
    for (int i = 0; i < 1001; ++i) {
        prime[i]= true;
    }
    for (int i = 2; i < 1001; ++i) {
        if(prime[i]){
            int j=i*i;
            while(1){
                if(j>1000)
                    break;
                prime[j]= false;
                j+=i;
            }
        }
    }
    ans[0]=0;
    ans[1]=0;
    ans[2]=1;
    ans[3]=1;
    int k=3,l=2;
    for (int i = 2; i < 1001; ++i) {
        if(prime[i]){
            cout<<i*i<<" ";
            while(k<=(i*i)){
                ans[k++]=ans[l];
            }
            ans[i*i]++;
            l=i*i;
        }
    }
//    while(k<=1000000){
////        ans[k++]=ans[l];
//    }
    return;
}

int main() {
    int q;
    cin>>q;
    sieve();
//    while(q--){
//        int a,b;
////        cin>>a>>b;
//        cout<<abs(ans[b]-ans[a])+(ans[a]-ans[a-1])<<endl;
//    }
    return 0;
}