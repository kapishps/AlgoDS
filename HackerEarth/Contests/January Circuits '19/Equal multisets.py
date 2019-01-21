#!/usr/bin/env python

if __name__ == '__main__':
    n = int(raw_input())
    a = map(int, raw_input().split())
    b = map(int, raw_input().split())

    a.sort()
    b.sort()

    ans = 0
    for i in range(0,n):
        ans += abs(a[i]-b[i])
        ans %= 1000000007

    print ans
