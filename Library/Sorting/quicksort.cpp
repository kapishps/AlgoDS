#include <iostream>

using namespace std;

int partition(int A[],int start,int end){
    int pivot=A[end];
    int Pindex=start;
    for(int i=start;i<end;i++){
        if(A[i]<pivot){
            swap(A[Pindex],A[i]);
            Pindex++;
        }
    }
    swap(A[Pindex],A[end]);
    return Pindex;
}

void quicksort(int A[],int start,int end){
    if(start>=end)
        return;
    int Pindex=partition(A,start,end);
    cout<<Pindex<<endl;
    quicksort(A,start,Pindex-1);
    quicksort(A,Pindex+1,end);
}

int main()
{
    int A[]={2,4,1,6,8,5,3,7};
    quicksort(A,0,7);
    for(int i=0;i<8;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}

