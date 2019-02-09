def solve (a,n):
    sum = 0;
    if n >= 2:
        for i in range(1,n):
            sum += abs(a[i] - a[i-1])
        diff = max(abs(a[1]-a[0]), abs(a[n-1]-a[n-2]))
        if n >= 3:
            for i in range(1,n-1):
                diff = max(diff, abs(a[i]-a[i-1]) + abs(a[i+1]-a[i]) - abs(a[i+1] - a[i-1]))
        sum -= diff
    return sum

T = input()
for _ in xrange(T):
    N = input()
    A = map(int, raw_input().split())
    out_ = solve(A,N)
    print out_
