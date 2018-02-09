#include "engine.h"


int main(void) {
  int success;
  success = generate_private_key();
  printf("%i\n", success);
}



int generate_private_key(void) {
  FILEHEADER fh;
  KEY k;

  srand(time(0));
  for (int i=0; i<sizeof(KEY); i++) {
    k.key[i] = rand()%255;
  }

  for (int i = 0; i<sizeof(FILETYPE); i++) {
    fh.fileType[i] = FILETYPE[i];
    printf("%c", FILETYPE[i]);
  }
  printf("\n");
  fh.headerLength = 0;
  fh.fileLength = sizeof(FILEHEADER) + sizeof(KEY);


  FILE *fp = fopen("key.n", "w");
  fwrite(&fh, sizeof(FILEHEADER), 1, fp);
  fwrite(&k, sizeof(KEY), 1, fp);
  fclose(fp);


  return 200;
}
