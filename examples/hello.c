#include "zlog.h"
#include <stdio.h>

// if zlog.conf in /etc, you may need superuser privilege to run this demo
#define CONF_FILE_PATH "./zlog.conf"

int main(int argc, char **argv) {
  int rc;
  zlog_category_t *c;

  if (argc < 2)
    rc = zlog_init("./zlog.conf");
  else
    rc = zlog_init(argv[1]);
  if (rc) {
    printf("init failed\n");
    return -1;
  }

  c = zlog_get_category("my_cat");
  if (!c) {
    printf("get cat fail\n");
    zlog_fini();
    return -2;
  }

  zlog_info(c, "hello, zlog");

  zlog_fini();

  return 0;
}