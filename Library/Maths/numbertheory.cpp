#include <iostream>
#include <vector>
using namespace std;

vector<bool> prime;

void SieveOfEratosthenes(int n) {
    prime.assign(n, true);
    for (int i=2; i*i<=n; i++) {
        if (prime[i] == true) {
            for (int j=i*2; j<=n; j += i)
                prime[j] = false;
        }
    }
}

int main() {
    int n;
    cin>>n;
    SieveOfEratosthenes(n);
    for (int i = 2; i < n; ++i) {
        if(prime[i])
            cout<<i<<" ";
    }
    return 0;
}
