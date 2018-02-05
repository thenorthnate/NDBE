// This file holds the functions responsible for reading and writing to files

package main

import (
  "os"
  "fmt"
  "math/rand"
)

const keyLen = 2000

func create_private_key() {
  cwd, _ := os.Getwd()
  filePath := cwd + "/key.n"
  f, err := os.Create(filePath)
  check(err)
  defer f.Close()

  for i := 0; i < keyLen; i++ {
    r := rand.Intn(255)
    fmt.Fprintf(f, "%v,", r)
  }

}


func check(e error) {
  if e != nil {
    panic(e)
  }
}
