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

var a [MAXN]int
var ans [MAXN]int

func preCompute(n int) {
	max := -inf
	for i := 0; i < n; i++ {
		ans[i] = 0
		if max < a[i] {
			max = a[i]
		}
	}
	ans[0] = max
}

func main() {
	input := bufio.NewScanner(os.Stdin)
	input.Split(bufio.ScanWords)
	// 	input.Scan()
	// 	t, _ := strconv.Atoi(input.Text())
	t := 1

	for t > 0 {
		input.Scan()
		n, _ := strconv.Atoi(input.Text())

		for i := 0; i < n; i++ {
			input.Scan()
			a[i], _ = strconv.Atoi(input.Text())
		}

		preCompute(n)

		input.Scan()
		q, _ := strconv.Atoi(input.Text())

		for q > 0 {
			input.Scan()
			m, _ := strconv.Atoi(input.Text())
			input.Scan()
			k, _ := strconv.Atoi(input.Text())

			if k == 0 {
				fmt.Printf("%v\n", a[m-1])
			} else if k == 1 {
				if ans[m-1] != 0 {
					fmt.Printf("%v\n", ans[m-1])
				} else {
					ans[m-1] = a[m-1]

					for i := 1; i*i <= m; i++ {
						if m%i == 0 && ans[m-1] < a[i-1] {
							ans[m-1] = a[i-1]
						}
						if m%i == 0 && ans[m-1] < a[(m/i)-1] {
							ans[m-1] = a[(m/i)-1]
						}
					}

					for i := m; i <= n; i = i + m {
						if ans[m-1] < a[i-1] {
							ans[m-1] = a[i-1]
						}
					}
					fmt.Printf("%v\n", ans[m-1])
				}

			} else {
				fmt.Printf("%v\n", ans[0])
			}

			q--
		}

		t--
	}
}
