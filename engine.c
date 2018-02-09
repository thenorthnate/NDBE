#include "engine.h"


int main(void) {
  int success;
  success = write_private_key();
  success = read_private_key();
  printf("DONE.\n");

  // sleep(3);
}



int write_private_key(void) {
  FILEHEADER fh;
  KEY k;
  srand(time(0));
  for (int i=0; i<sizeof(KEY); i++) {
    k.key[i] = (char) rand()%255;
  }
  for (int i = 0; i<sizeof(FILETYPE); i++) {
    fh.fileType[i] = FILETYPE[i];
  }
  fh.headerLength = 0;
  fh.fileLength = sizeof(FILEHEADER) + sizeof(KEY);
  fh.tableCount = 1;

  FILE *fp = fopen("key.n", "w");
  if (fp == NULL) {
    return 403;
  }
  fwrite(&fh, sizeof(FILEHEADER), 1, fp);
  fwrite(&k, sizeof(KEY), 1, fp);
  fclose(fp);
  return 200;
}


int read_private_key(void) {
  FILEHEADER fh;
  KEY k;

  char *infile = "key.n";

  FILE *inptr = fopen(infile, "r");
  if (inptr == NULL) {
    fprintf(stderr, "Could not open file: %s\n", infile);
    return 403;
  }
  fread(&fh, sizeof(FILEHEADER), 1, inptr);
  fread(&k, sizeof(KEY), 1, inptr);
  fclose(inptr);

  printf("The key file has: %llu bytes in it.\n", fh.fileLength);
  return 200;
}
