package main

import (
	"code.google.com/p/go-tour/wc"
	"fmt"
)

func LetterCount(s string) map[string]int {
	strmap := make(map[string]int)
	str := string("");
	if len(s) == 0{
		return nil
	}
	for _,v := range(s) {
		if v == ' ' {
			if len(str) == 0 {
				continue
			}else {
				strmap[str] = len(str)
				str = ""
			}
		}else {
			str = str + string(v)
		}
	}
	return strmap
}

func WordCount(s string) map[string]int {
	strmap := make(map[string]int)
	str := string("");
	for i, v := range (s) {
		if (i == len(s)-1)&&(v != ' ') {
			str = str + string(v)
			strmap[str]++
		}else {
			if (v == ' ')&&(len(str) == 0) {
				continue
			}else {
				if v == ' ' {
					strmap[str]++
					str = ""
				}else{
					str = str + string(v)
				}
			}
		}
	}
	return strmap
}

func main() {
	fmt.Println("---")
	//fmt.Print(LetterCount("I am learning Go  "))
	//for i,v := range(LetterCount("  I am learning Go!")){
	//	fmt.Println(i,v);
	//}
	fmt.Println("---")
	fmt.Println(WordCount("I am learning Go!"))
	wc.Test(WordCount)
}

