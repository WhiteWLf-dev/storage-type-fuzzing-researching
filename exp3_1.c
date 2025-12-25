//./exp3_1 -fork=1 -ignore_crashes=1 /mnt/ramdisk/exp3_1/inputs/ # exp3_1 dir on RAM
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include <haproxy/cfgparse.h>
#include "./src/cfgparse-tcp.c"

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
      char filename[256];
      sprintf(filename, "/mnt/ramdisk/exp3_1/exp3cfg.%d", getpid());

      FILE *fp = fopen(filename, "wb");
      if (!fp) {
        exit(1);
      }

      fwrite(Data, Size, 1, fp);
      fclose(fp);

      readcfgfile(filename); //target function

      unlink(filename);
}
