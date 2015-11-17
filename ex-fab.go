package main

import "fmt"

// fibonacci 函数会返回一个返回 int 的函数。
func fibonacci() func() int {
	count := 1; p := 1; q := 1;
	return func() int {
	   if count == 1 || count == 2 {
		   count ++;
		   return 1
	   }
	   p, q = q, p+q;
	   return q
   }
}

func main() {
	f := fibonacci()
    for i := 0; i < 10; i++ {
	   fmt.Println(f())
   }
}

