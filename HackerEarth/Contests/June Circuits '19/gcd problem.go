package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const inf int = 2147483647
const MOD int = 1e9 + 7
const MAXN int = 1e5 + 9

func power_mod(num int, pow int, m int) int {
	cnt := 1
	for pow > 0 {
		if pow%2 == 1 {
			cnt = (cnt * num) % m
		}
		pow /= 2
		num = (num * num) % m
	}
	return cnt
}

func solve(n int) []int {
	f := make([]int, MAXN)
	for i := 1; i <= n; i++ {
		for d := 1; d*d <= i; d++ {
			if i%d == 0 {
				f[d]++
				if d*d < i {
					f[i/d]++
				}
			}
		}
	}

	ans := make([]int, MAXN)
	for i := n; i >= 1; i-- {
		ans[i] = f[i] * (f[i] - 1) * (f[i] - 2) * (f[i] - 3) / 24
		for j := i * 2; j <= n; j += i {
			ans[i] -= ans[j]
		}
		ans[i] %= MOD
	}

	return ans
}

func main() {
	input := bufio.NewScanner(os.Stdin)
	input.Split(bufio.ScanWords)
	input.Scan()
	t, _ := strconv.Atoi(input.Text())

	for t > 0 {
		input.Scan()
		n, _ := strconv.Atoi(input.Text())

		cnt := solve(n)
		ans := 0
		for j := 1; j*4 <= n; j++ {
			ans += power_mod(j, 4, MOD) * cnt[j]
			ans %= MOD
		}

		fmt.Printf("%v\n", ans)
		t--
	}
}
