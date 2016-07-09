#include <iostream>

using namespace std;

void mergearray(int A[],int L[],int R[],int n){
    int l=n/2;
    int r=n-l;
    int i,j,k;

	i = 0; j = 0; k =0;

	while(i<l && j< r) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < l) A[k++] = L[i++];
	while(j < r) A[k++] = R[j++];
}

void mergesort(int A[],int n){
    if(n<2)
        return;
    int *L,*R;
    int mid=n/2;
    L=new int[mid];
    R=new int[n-mid];
    for(int i=0;i<mid;i++){
        L[i]=A[i];
    }
    for(int i=0;i<n-mid;i++){
        R[i]=A[mid+i];
    }
    mergesort(L,mid);
    mergesort(R,n-mid);
    mergearray(A,L,R,n);
    delete L;
    delete R;
}

//https://gist.github.com/mycodeschool/9678029

int main()
{
    int A[]={2,4,1,6,8,5,3,7};
    mergesort(A,8);
    for(int i=0;i<8;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}
