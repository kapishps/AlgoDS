int Solution::gcd(int A, int B) {
    if (A < B) {
        int t = A;
        A = B;
        B = t;
    }
    if (B == 0)
        return A;
    return gcd(B, A % B);
}
