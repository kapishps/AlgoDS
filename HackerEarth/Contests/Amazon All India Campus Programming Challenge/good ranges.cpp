#include<bits/stdc++.h>
using namespace std;

int a[1000009];
map<int,int> map1;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    long long N, M, X, sum = 0;
    cin >> N >> M;

    int minX,maxX;
    for(int i =0 ;i< M;i++){
        cin>>a[i];
        if(map1[a[i]] == 0){
            if(i == 0){
                minX = a[i];
                maxX = a[i];
                sum += (1+N);
            }
            else{
                if(a[i]< minX){
                    sum += (a[i] + minX);
                    minX = a[i];
                }
                else if (a[i] > maxX){
                    sum += (a[i] + maxX);
                    maxX = a[i];
                }
                else{
                    sum += (a[i] + a[i]);
                }
            }
        }
        map1[a[i]]++;
        cout<<sum<<"\n";
    }
}