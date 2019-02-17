def solve(Arr, n):
    a = [Arr[n-1]]
    b = [Arr[n-1]]
    for i in xrange(1,n):
        a.append(max(Arr[n-i-1] - b[i-1], a[i-1]))
        b.append(min(Arr[n-i-1] - a[i-1], b[i-1]))
    return max(a[n-1], b[n-1])

T = input()
for _ in xrange(T):
    N = input()
    Arr = map(int, raw_input().split())
    out_ = solve(Arr, N)
    print out_
