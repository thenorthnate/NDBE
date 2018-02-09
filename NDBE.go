package main

// NOTE
// This is the .n database engine
// It is simply a TCP server that handles the reading and writing of .n files
// per the request made to it at localhost


import (
  "fmt"
  "os"
  //"net"
)

var response int

func main() {
  // run the main code here!
  cwd, _ := os.Getwd()
  filePath := cwd + "/key.n"

  response = create_private_key(filePath)
  fmt.Printf("Response: %v\n", response)
}
