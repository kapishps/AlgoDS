#include <iostream>

using namespace std;

void bubblesort(int A[],int n){
    for(int i=0;i<n-1;i++){
        int flag=0;
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
                flag=1;
            }
        }
        if(flag==0)
        break;
    }
}

int main()
{
    int A[]={2,7,1,5,3};
    bubblesort(A,5);
    for(int i=0;i<5;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}

