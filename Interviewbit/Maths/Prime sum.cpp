#include <bitset>
bitset<20000010> prime;

void sieve(int A) {
    prime.set();
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= A; ++i) {
        int j = i * 2;
        // if(prime[i])
        //     cout<<i<<" ";
        while (prime[i] && j <= A) {
            prime[j] = 0;
            j += i;
        }
    }
}

vector<int> Solution::primesum(int A) {
    sieve(A);
    vector<int> ans;
    for (int i = 0; i <= A / 2; ++i) {
        if (prime[i] && prime[A - i]) {
            ans.push_back(i);
            ans.push_back(A - i);
            break;
        }
    }
    return ans;
}
