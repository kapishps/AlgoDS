package main
 
import (
	"C"
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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
 
// var a [MAXN]int
 
 
func sliceAtof(sa []string) ([]float64, error) {
    si := make([]float64, 0, len(sa))
    for _, a := range sa {
        i, err := strconv.ParseFloat(a, 64)
        if err != nil {
            return si, err
        }
        si = append(si, i)
    }
    return si, nil
}
 
 
 
func main() {
	input := bufio.NewScanner(os.Stdin)
	input.Split(bufio.ScanLines)
	
	input.Scan()
	d, _ := strconv.ParseFloat(input.Text(), 64)
	input.Scan()
	o := strings.Split(input.Text(), " ")
	input.Scan()
	c := strings.Split(input.Text(), " ")
 
	
	a, _ := sliceAtof(o)
	b, _ := sliceAtof(c)
	
 
    oc := a[0]
    if d > a[1] {
        oc += a[2]*(d - a[1])
    }
    cc := b[1]
    cc += (d/b[0])*b[2]
    cc += d*b[3]
    
    if oc <= cc {
        fmt.Printf("Online Taxi\n")
    } else {
        fmt.Printf("Classic Taxi\n")
    }
 
}