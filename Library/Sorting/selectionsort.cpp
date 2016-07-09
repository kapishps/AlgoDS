#include <iostream>

using namespace std;

void selectionsort(int A[],int n){
    int maxi,temp;
    for(int i=0;i<n-1;i++){
        maxi=i;
        for(int j=i;j<n;j++){
            if(A[j]>A[maxi])
                maxi=j;
        }
        temp=A[i];
        A[i]=A[maxi];
        A[maxi]=temp;
    }
}

int main() {
    int A[]={2,5,7,4,3};
    selectionsort(A,5);
    for(int i=0;i<5;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}

