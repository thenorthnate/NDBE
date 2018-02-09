// This file holds the functions responsible for reading and writing to files

package main

import (
  "os"
  "fmt"
  "math/rand"
  "bufio"
  "time"
)

const keyLen = 2000


func check(e error) {
  if e != nil {
    panic(e)
  }
}


func write_bytes_to_file(filePath string, byteSlice []byte) int {
  return 0
}

func create_private_key(filePath string) int {
  f, err := os.Create(filePath)
  check(err)
  defer f.Close()
  r := rand.New(rand.NewSource(time.Now().UnixNano()))
  w := bufio.NewWriter(f)
  for i := 0; i < keyLen; i++ {
    w.WriteByte(byte(r.Intn(255)))
  }
  w.Flush()
  // This should actually be returned through the TCP server!
  fmt.Printf("Created private key at: %v\n", filePath)
  return 200
}
