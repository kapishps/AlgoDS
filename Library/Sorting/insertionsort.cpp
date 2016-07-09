#include <iostream>

using namespace std;

void insertionsort(int A[],int n){
    for(int i=1;i<n;i++){
        int value=A[i];
        int h=i;
        while(h!=0 && value<A[h-1]){
            A[h]=A[h-1];
            h--;
        }
        A[h]=value;
    }
}

int main()
{
    int A[]={2,7,1,5,3};
    insertionsort(A,5);
    for(int i=0;i<5;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}

