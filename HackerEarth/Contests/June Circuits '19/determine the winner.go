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
	input.Split(bufio.ScanWords)
	input.Scan()
	t, _ := strconv.Atoi(input.Text())

	for t > 0 {
		input.Scan()
		n, _ := strconv.Atoi(input.Text())
		input.Scan()
		k, _ := strconv.Atoi(input.Text())

		if n%(k+1) == 0 {
			fmt.Println("Dishant")
		} else {
			fmt.Println("Arpa")
		}

		t--
	}
}
