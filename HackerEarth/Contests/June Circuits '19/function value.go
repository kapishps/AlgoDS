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

var arr []int
var x int
var y int

func extendedEuclid(a int, b int) {
	if b == 0 {
		arr = a
		x = 1
		y = 0
	} else {
		extendedEuclid(b, a%b)
		temp := x
		x = y
		y = temp - (a/b)*y
	}
}

func modulo_Inv(a int, m int) int {
	extendedEuclid(a, m)
	return ((x % m) + m) % m
}

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

func gpsum(a int, n int, mod int) int {
	if n <= 1 {
		return 1
	}

	result := ((1 + power_mod(a, n/2, mod)) * gpsum(a, n/2, mod)) % mod
	if n%2 == 1 {
		result += power_mod(a, n-1, mod)
	}
	return result % mod
}

func solve(n int, mod int) int {
	if n == 0 {
		return 0
	} else if n == 1 {
		return 1
	} else if n == 2 {
		return 2
	}

	ans := 0
	if n%2 == 1 {
		ans += gpsum(3, (n/2)+1, mod)
		n--
		if n%4 == 0 {
			ans += 6 * gpsum(9, n/4, mod)
			ans += 2 * (n / 4)
			ans %= mod
		} else {
			if n > 2 {
				ans += 18 * gpsum(9, (n-2)/4, mod)
				ans += 2 * (n / 4)
			}
			ans++
			ans %= mod
		}
	} else {
		if n%4 == 0 {
			ans += 6 * gpsum(9, n/4, mod)
			ans += 2 * (n / 4)
			ans %= mod
		} else {
			if n > 2 {
				ans += 18 * gpsum(9, (n-2)/4, mod)
				ans += 2 * (n / 4)
			}
			ans += 1
			ans %= mod
		}
		n--
		ans += gpsum(3, (n/2)+1, mod)
		ans %= mod
	}
	return ans
}

func main() {
	input := bufio.NewScanner(os.Stdin)
	input.Split(bufio.ScanWords)
	input.Scan()
	t, _ := strconv.Atoi(input.Text())
	input.Scan()
	mod, _ := strconv.Atoi(input.Text())

	for t > 0 {
		input.Scan()
		l, _ := strconv.Atoi(input.Text())
		input.Scan()
		r, _ := strconv.Atoi(input.Text())

		fmt.Printf("%v\n", (solve(r, mod)-solve(l-1, mod)+mod)%mod)
		t--
	}
}
