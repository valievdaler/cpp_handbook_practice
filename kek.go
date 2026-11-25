package main

import (
	"fmt"
	"io"
	"net/http"
	"os"
	"time"
)

func fetch(addr string, ch chan<- string) {
	start := time.Now()

	resp, err := http.Get(addr)
	if err != nil {
		ch <- fmt.Sprint(err)
		return
	}
	defer resp.Body.Close()
	nbytes, err := io.Copy(io.Discard, resp.Body)

	if err != nil {
		ch <- fmt.Sprint(err)
		return
	}

	secs := time.Since(start).Seconds()

	ch <- fmt.Sprintf("%.2fs %d %s", secs, nbytes, addr)
}

func main() {
	ch := make(chan string)
	if len(os.Args) < 2 {
		fmt.Println("Please provide URLSs")
		return
	}
	for _, line := range os.Args[1:] {
		go fetch(line, ch)

	}

	for range os.Args[1:] {
		fmt.Println(<-ch)
	}

}
