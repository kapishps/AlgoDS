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
 
var fact [MAXN]int
 
func preCompute() {
	fact[0] = 1
	for i := 1; i <= 1000000; i++ {
		fact[i] = fact[i-1] * i
		fact[i] %= MOD
	}
}
 
func main() {
	input := bufio.NewScanner(os.Stdin)
	input.Split(bufio.ScanWords)
// 	input.Scan()
// 	t, _ := strconv.Atoi(input.Text())
    t := 1
 
	preCompute()
 
	for t > 0 {
		input.Scan()
		n, _ := strconv.Atoi(input.Text())
		_ = n
		input.Scan()
		m, _ := strconv.Atoi(input.Text())
 
		ans := fact[m]
 
		fmt.Printf("%v\n", (ans)%MOD)
 
		t--
	}
}