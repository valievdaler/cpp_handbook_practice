package main

import (
	"fmt"
	"log"
	"net/http"
	"sync"
)

var count int
var mutex sync.Mutex

func handler(w http.ResponseWriter, r *http.Request) {
	mutex.Lock()
	count++
	mutex.Unlock()
	fmt.Fprintf(w, "URL.path=%q\n", r.URL.Path)
}

func counter(w http.ResponseWriter, r *http.Request) {
	mutex.Lock()
	fmt.Fprintf(w, "Count %d\n", count)
	mutex.Unlock()
}

func main() {
	http.HandleFunc("/", handler)
	http.HandleFunc("/count", counter)
	log.Fatal(http.ListenAndServe("localhost:8000", nil))
}
