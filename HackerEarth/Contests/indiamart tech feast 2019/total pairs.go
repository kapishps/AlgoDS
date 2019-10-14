package main

import (
	"C"
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type pair struct {
	a, b interface{}
}

// Constants
const (
	inf  int = 2147483647
	MOD  int = 1e9 + 7
	MAXN int = 1e6 + 9
)

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

func solve(n int, k int) int {
	return (power_mod(k, n, MOD)) % MOD
}

func main() {
	input := bufio.NewScanner(os.Stdin)
	input.Split(bufio.ScanWords)
	input.Scan()
	t, _ := strconv.Atoi(input.Text())

	for t > 0 {
		input.Scan()
		n, _ := strconv.Atoi(input.Text())
		input.Scan()
		k, _ := strconv.Atoi(input.Text())

		ans := 0

		if n%2 == 0 {
			p := solve(n/2, k)
			np := solve(n, k) - p + MOD
			np %= MOD
			ans = (p * np) % MOD

		} else {
			p := (solve(n/2, k) * k) % MOD
			np := solve(n, k) - p + MOD
			np %= MOD
			ans = (p * np) % MOD
		}

		fmt.Printf("%v\n", ans)
		t--
	}
}
