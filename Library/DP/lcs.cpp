#include <iostream>
#include <string>

using namespace std;

void lcs(string s1,string s2,int n,int m){
    int l[n+1][m+1];
    for (int i = 0; i <=n; ++i) {
        for (int j = 0; j <=m; ++j) {
            if(i==0 || j==0)
                l[i][j]=0;
            else if(s1[i-1]==s2[j-1])
                l[i][j]=l[i-1][j-1]+1;
            else
                l[i][j]=max(l[i-1][j],l[i][j-1]);
        }
    }
    int i=n,j=m;
    string s;
    while (i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s.insert(s.begin(),s1[i-1]);
            i--;
            j--;
        }
        else if(l[i-1][j]>l[i][j-1])
            i--;
        else
            j--;
    }
    cout<<s;
}

int main(){
    string s1,s2;
    s1="12341";
    s2="341213";
    int n=s1.size(),m=s2.size();
    lcs(s1,s2,n,m);
    return 0;
}
