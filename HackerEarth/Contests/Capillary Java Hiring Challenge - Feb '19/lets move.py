def subArraySum(Arr, n, Sum):
    Map = {}
    curr_sum = 0
    for i in xrange(n):
        curr_sum = curr_sum + Arr[i]
        if curr_sum == Sum:
            return True
        if (curr_sum - Sum) in Map:
            return True
        Map[curr_sum] = i
    return False

def solve(S, N, X, Y):
    ans = 0
    Arr = []
    for i in xrange(len(S)):
        if S[i] == "U":
            Arr.append(1)
        if S[i] == "D":
            Arr.append(-1)
        if S[i] == "L":
            Arr.append(-10000)
        if S[i] == "R":
            Arr.append(10000)
    # print Arr
    for i in xrange(N):
        sum = (X[i]*10000) + Y[i]
        if subArraySum(Arr, len(Arr), sum) == True or sum == 0:
            ans += 1
    return ans

T = input()
for _ in xrange(T):
    S = raw_input()
    Q = input()
    X = map(int, raw_input().split())
    Y = map(int, raw_input().split())
    out_ = solve(S, Q, X, Y)
    print out_
