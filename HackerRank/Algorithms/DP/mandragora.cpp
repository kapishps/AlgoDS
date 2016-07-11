#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//https://www.hackerrank.com/challenges/mandragora

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector <int> v(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            sum+=v[i];
        }
        sort(v.begin(),v.end());
        long long s=1,p=0;
        for(int i=0;i<n;i++){
            int t=v[i];
            if(sum*s<(sum-t)*(s+1)){
                s=s+1;
                sum=(sum-t);
            }
            else{
                p+=s*t;
                sum=sum-t;
            }
        }
        cout<<p<<endl;
    }
    return 0;
}