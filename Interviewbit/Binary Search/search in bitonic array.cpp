int solve(int* A, int n1, int B) {

    //find inflection point
    int start = 0, end = n1-1, mid;
    while(start < end){
        mid = (start+end)/2;
        if(A[mid-1] < A[mid] && A[mid] > A[mid+1]){
            break;
        }
        else if(A[mid-1] < A[mid] && A[mid] < A[mid+1]){
            start = mid;
        } else {
            end = mid;
        }
    }
    int inflection = mid;

    // search in first half
    start = 0, end = inflection;
    while(start < end){
        mid = (start+end)/2;
        if(A[mid] < B){
            start = mid+1;
        } else {
            end = mid;
        }
    }
    if(A[start] == B){
        return start;
    }

    // search in second half
    start = inflection+1, end = n1-1;
    while(start < end){
        mid = (start+end)/2;
        if(A[mid] > B){
            start = mid+1;
        } else {
            end = mid;
        }
    }
    if(A[start] == B){
        return start;
    }
    return -1;
}