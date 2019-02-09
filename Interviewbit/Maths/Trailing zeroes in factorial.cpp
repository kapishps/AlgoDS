int Solution::trailingZeroes(int A) {
    int ans = 0, five = 5;
    for (int i = 1; i <= 11; i++) {
        ans += A / five;
        five *= 5;
    }
    return ans;
}
