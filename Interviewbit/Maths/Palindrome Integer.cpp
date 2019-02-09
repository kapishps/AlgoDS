int Solution::isPalindrome(int A) {
    long long ans = 0;
    if (A < 0) {
        return 0;
    }

    int B = A;
    while (A) {
        ans *= 10;
        ans += A % 10;
        A /= 10;
    }

    return ans == B;
}
