package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
)

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