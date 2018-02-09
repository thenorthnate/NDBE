#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define FILETYPE ".n"

int generate_private_key(void);


typedef struct {
  char fileType[2];
  unsigned headerLength;
  unsigned long long fileLength;
  unsigned tableCount;
} FILEHEADER; //fh


typedef struct {
  char *privateKeyPath;
  unsigned char usernameLength;
  char *username;
  unsigned char passwordLength;
  char *password;
} USERHEADER; //uh


typedef struct COL{
  unsigned nameLength;
  char *name;
  struct COL *next;
} COL; //col


typedef struct {
  char key[1024];
} KEY;
