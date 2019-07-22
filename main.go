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

var arr [MAXN]int

func main() {
	input := bufio.NewScanner(os.Stdin)
	input.Split(bufio.ScanWords)
	input.Scan()
	t, _ := strconv.Atoi(input.Text())

	for t > 0 {
		input.Scan()
		n, _ := strconv.Atoi(input.Text())
		fmt.Println("Hello World!")
		fmt.Printf("%v", n)
		t--
	}
}
