def solve(n):
    bits = []
    nums = []
    while n > 0:
        if n%2 == 1:
            bits.append(1)
        else:
            bits.append(0)
        n //= 2

    for i in range(len(bits)):
        if bits[i] == 1:
            nums.append(str(3**i))
    return nums


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        N = int(input())
        out_ = solve(N)
        print(len(out_))
        print(' '.join(out_))