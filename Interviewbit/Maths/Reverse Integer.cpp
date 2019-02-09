int Solution::reverse(int A) {
    long long ans = 0;
    int neg = 0;
    if (A < 0) {
        neg = 1;
        A = -A;
    }
    while (A) {
        ans *= 10;
        ans += A % 10;
        A /= 10;
        if (ans > 2147483647)
            return 0;
    }

    if (neg)
        ans = -ans;

    return ans;
}
