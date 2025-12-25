//./exp3_3 -fork=1 -ignore_crashes=1 /exp3_3/inputs/ # exp3_3 dir on HDD
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include <haproxy/cfgparse.h>
#include "./src/cfgparse-tcp.c"

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
      char filename[256];
      sprintf(filename, "exp3_2/exp3cfg.%d", getpid()); // exp3_3 on HDD here

      FILE *fp = fopen(filename, "wb");
      if (!fp) {
        exit(1);
      }

      fwrite(Data, Size, 1, fp);
      fclose(fp);

      readcfgfile(filename); //target function

      unlink(filename);
}
