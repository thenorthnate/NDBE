#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define FILETYPE ".n"
#define KEYLENGTH 1024

int write_private_key(void);
int read_private_key(void);


typedef struct {
  char fileType[sizeof(FILETYPE)];
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

typedef struct {
  unsigned char tableNameLength;
  char *tableName;
} TABLE;


typedef struct {
  unsigned nameLength;
  char *name;
} TABLECOLUMN; //tc


typedef struct {
  char key[KEYLENGTH];
} KEY;
