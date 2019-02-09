T = 0
N = 0
val = []
h = []
M = 0
I = []
min_height = []
height = []

dp = {}

# Wrong Answer in all

def solve(idx, curr_h):
    curr_h = min(curr_h,1001)
    if idx >= N:
        return 0
    if curr_h < height[idx]:
        return -1000000000000000
    if (idx, curr_h) in dp:
        return dp[(idx, curr_h)]
    dp[(idx, curr_h)] = max(solve(idx+1, curr_h + h[idx]), val[idx] + solve(idx+1, curr_h))
    return dp[(idx, curr_h)]

T = input()
for _ in xrange(T):
    N = input()
    val = map(int, raw_input().split())
    h = map(int, raw_input().split())
    M = input()
    I = map(int, raw_input().split())
    min_height = map(int, raw_input().split())

    height = [0] * 1000
    for i in range(M):
        height[I[i]] = min_height[i]

    dp = {}

    out_ = solve(0,0)
    if out_ < 0:
        out_ = -1
    print out_
