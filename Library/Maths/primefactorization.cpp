#include <cmath>
#include <iostream>
#include <map>
using namespace std;

map<long long,int> map1;            // <prime no.,frequency>

void primeFactors(long long n) {
    while (n%2 == 0) {
        map1[2]++;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2) {
        while (n%i == 0) {
            map1[i]++;
            n = n/i;
        }
    }
    if (n > 2)
        map1[n]++;
}

int main() {
    long long n;
    cin>>n;
    primeFactors(n);
    for(auto a:map1){
        cout<<a.first<<":"<<a.second<<" ";
    }
    return 0;
}
