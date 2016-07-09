#include <iostream>

using namespace std;

int parent[100001],rnk[100001];

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    x = findset(x), y = findset(y);
    if (rnk[x] > rnk[y])
        parent[y] = x;
    else
        parent[x] = y;
    if (rnk[x] == rnk[y])
        rnk[y]++;
}

//https://www.hackerrank.com/challenges/journey-to-the-moon/

int main()
{
    int N, I;
    cin >> N >> I;
    for(int i=0;i<N;i++){
        parent[i]=i;
        rnk[i]=0;
    }
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        unionset(a,b);
    }
    int hash[100001]={0};
    for(int i=0;i<N;i++){
        findset(i);
        hash[parent[i]]++;
        //cout<<parent[i]<<" ";
    }
    long long result = 0;
    /** Write code to compute the result using N,I,pairs **/

    for (int i = 0; i < N; i++)
        result+= N - hash[parent[i]];

    cout << result/2<< endl;
    return 0;
}
