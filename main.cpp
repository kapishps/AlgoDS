#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin>>n;
    unordered_set<int> s;
    for (int i = 2; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(__gcd(i,j)==1)
                s.insert(i*j);
        }
    }
    cout<<s.size();
    return 0;
}