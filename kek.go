package main

import (
	"bufio"
	"fmt"
	"os"
)

func countLines(f *os.File, counts map[string]int) {
	input := bufio.NewScanner(f)
	for input.Scan() {
		counts[input.Text()]++
	}

	if err := input.Err(); err != nil {
		fmt.Fprintf(os.Stderr, "Error %v ", err)
	}
}

func main() {

	counts := make(map[string]int)
	files := os.Args[1:]

	if len(files) == 0 {
		countLines(os.Stdin, counts)
	} else {
		for _, arg := range files {
			f, err := os.Open(arg)

			if err != nil {
				fmt.Fprintf(os.Stderr, " Error %v ", err)
				continue
			}
			countLines(f,counts)
			f.Close()
		}
	}

	for line,n:=range counts{
		if n > 1{
			fmt.Printf("Index %d\tElements %s\n",n,line)
		}
	}
}