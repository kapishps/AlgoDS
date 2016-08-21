#include <iostream>
#include <vector>
using namespace std;

//Range Minimum Query

class SegmentTree {                         // the segment tree is stored like a heap array
private: vector<int> segtree, A;
    int n;
    int left (int p) {                  // same as binary heap operations
        return p << 1;
    }
    int right(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {           // O(n log n)
        if (L == R)                            // as L == R, either one is fine
            segtree[p] = L;                                         // store the index
        else {                                // recursively compute the values
            build(left(p) , L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = segtree[left(p)], p2 = segtree[right(p)];
            segtree[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j) {                  // O(log n)
        if (i > R || j < L) return -1; // current segment outside query range
        if (L >= i && R <= j) return segtree[p];               // inside query range

        // compute the min position in the left and right part of the interval
        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

        if (p1 == -1) return p2;   // if we try to access segment outside query
        if (p2 == -1) return p1;                               // same as above
        return (A[p1] <= A[p2]) ? p1 : p2;           // as as in build routine
    }

    int update_point(int p, int L, int R, int idx, int new_value) {
        // this update code is still preliminary, i == j
        // must be able to update range in the future!
        int i = idx, j = idx;

        // if the current interval does not intersect
        // the update interval, return this st node value!
        if (i > R || j < L)
            return segtree[p];

        // if the current interval is included in the update range,
        // update that st[node]
        if (L == i && R == j) {
            A[i] = new_value; // update the underlying array
            return segtree[p] = L; // this index
        }

        // compute the minimum position in the
        // left and right part of the interval
        int p1, p2;
        p1 = update_point(left(p) , L              , (L + R) / 2, idx, new_value);
        p2 = update_point(right(p), (L + R) / 2 + 1, R          , idx, new_value);

        // return the position where the overall minimum is
        return segtree[p] = (A[p1] <= A[p2]) ? p1 : p2;
    }

public:
    SegmentTree(const vector<int> &_A) {
        A = _A; n = (int)A.size();              // copy content for local usage
        segtree.assign(4 * n, 0);               // create large enough vector of zeroes
        build(1, 0, n - 1);                     // recursive build
    }

    int rmq(int i, int j) {
        return rmq(1, 0, n - 1, i, j);          // overloading
    }

    int update_point(int idx, int new_value) {
        return update_point(1, 0, n - 1, idx, new_value);
    }
};

int main() {
    int arr[] = { 18, 17, 13, 19, 15, 11, 20 };         // the original array
    vector<int> A(arr, arr + 7);                      // copy the contents to a vector
    SegmentTree segtree(A);

    printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
    printf("              A is {18,17,13,19,15, 11,20}\n");
    printf("RMQ(1, 3) = %d\n", segtree.rmq(1, 3));             // answer = index 2
    printf("RMQ(4, 6) = %d\n", segtree.rmq(4, 6));             // answer = index 5
    printf("RMQ(3, 4) = %d\n", segtree.rmq(3, 4));             // answer = index 4
    printf("RMQ(0, 0) = %d\n", segtree.rmq(0, 0));             // answer = index 0
    printf("RMQ(0, 1) = %d\n", segtree.rmq(0, 1));             // answer = index 1
    printf("RMQ(0, 6) = %d\n", segtree.rmq(0, 6));             // answer = index 5

    printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
    printf("Now, modify A into {18,17,13,19,15,100,20}\n");
    segtree.update_point(5, 100);                    // update A[5] from 11 to 100
    printf("These values do not change\n");
    printf("RMQ(1, 3) = %d\n", segtree.rmq(1, 3));                            // 2
    printf("RMQ(3, 4) = %d\n", segtree.rmq(3, 4));                            // 4
    printf("RMQ(0, 0) = %d\n", segtree.rmq(0, 0));                            // 0
    printf("RMQ(0, 1) = %d\n", segtree.rmq(0, 1));                            // 1
    printf("These values change\n");
    printf("RMQ(0, 6) = %d\n", segtree.rmq(0, 6));                         // 5->2
    printf("RMQ(4, 6) = %d\n", segtree.rmq(4, 6));                         // 5->4
    printf("RMQ(4, 5) = %d\n", segtree.rmq(4, 5));                         // 5->4

    return 0;
}