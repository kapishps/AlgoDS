// Maximum Contiguous Subsequence Product

#include <iostream>
using namespace std;

//Q:Find the contiguous subarray within an array (containing at least one number)
// which has the largest product.
//Input1:
//7
//1 -2 -3 0 7 -8 -2
//Output1:
//112
//Input2:
//4
//2 3 -2 4
//Output2:
//6

int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int max_ending_here,min_ending_here,max_so_far;
    max_ending_here = max_so_far = min_ending_here = a[0];
    int temp_max,temp_min;
    for (int i = 1; i < n; ++i) {
        temp_max = max (a[i], max (max_ending_here * a[i],min_ending_here * a[i]));
        temp_min = min (a[i], min (max_ending_here * a[i],min_ending_here * a[i]));
        max_so_far = max(max_so_far, temp_max);
        max_ending_here = temp_max;
        min_ending_here = temp_min;
    }
    cout<<max_so_far;
    return 0;
}
