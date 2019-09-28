def solve(arr, n):
    return "hello {}".format("world")


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        N = int(input())
        Arr = map(int, input().split())
        out_ = solve(Arr, N)
        print(out_)
