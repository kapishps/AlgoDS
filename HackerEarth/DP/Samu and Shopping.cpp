#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

long long solve(int arr[][3],int n){
    long long dist[n+2][3];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(i==0)
                dist[i][j]=arr[i][j];
            else
                dist[i][j]=INT_MAX;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if(j!=k){
                    dist[i][k]=min(dist[i][k],dist[i-1][j]+arr[i][k]);
                }
            }
        }
    }
    return min(dist[n-1][0],min(dist[n-1][1],dist[n-1][2]));
}

//https://www.hackerearth.com/code-monk-dynamic-programming/algorithm/samu-and-shopping/

int main() {
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int arr[n+10][3];
        for (int i = 0; i < n; ++i) {
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        }
        cout<<solve(arr,n)<<endl;
    }
    return 0;
}
