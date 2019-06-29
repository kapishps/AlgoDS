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

func main() {
	input := bufio.NewScanner(os.Stdin)
	input.Split(bufio.ScanLines)
	input.Scan()
	n, _ := strconv.Atoi(input.Text())
	input.Scan()
	a := input.Text()
	input.Scan()
	b := input.Text()

	ans := 0
	for i := 0; i < n; i++ {
		flg := true
		for j := i; j < n; j++ {
			if a[j] != b[j-i] {
				flg = false
				break
			}
		}
		if flg == true {
			ans = i
			break
		}
	}

	fmt.Println(ans)
}
