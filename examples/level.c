#include "category.h"
#include "zlog.h"
#include <stdio.h>

// if zlog.conf in /etc, you may need superuser privilege to run this demo
#define CONF_FILE_PATH "./zlog.conf"

static void print_levels(zlog_category_t *zc) {
  int i;
  printf("emerg: %d, alert: %d, crit: %d, err: %d, warning: %d, notice: %d, info: %d, debug: %d\n",
         zlog_level_enabled(zc, ZLOG_LEVEL_CRIT), zlog_level_enabled(zc, ZLOG_LEVEL_ERR),
         zlog_level_enabled(zc, ZLOG_LEVEL_EMERG), zlog_level_enabled(zc, ZLOG_LEVEL_ALERT),
         zlog_level_enabled(zc, ZLOG_LEVEL_WARNING), zlog_level_enabled(zc, ZLOG_LEVEL_NOTICE),
         zlog_level_enabled(zc, ZLOG_LEVEL_INFO), zlog_level_enabled(zc, ZLOG_LEVEL_DEBUG));
  printf("bitmap: %x, [ ", zc->level_bitmap);
  for (i = 7; i >= 0; i--) {
    printf("%d ", !!(zc->level_bitmap & (1 << i)));
  }
  printf("]\n");
}

static void print_logs(zlog_category_t *c) {
  zlog_emerg(c, "EMERG EMERG EMERG");
  zlog_alert(c, "ALERT ALERT ALERT");
  zlog_crit(c, "CRIT CRIT CRIT");
  zlog_error(c, "ERR ERR ERR");
  zlog_warn(c, "WARNING WARNING WARNING");
  zlog_notice(c, "NOTICE NOTICE NOTCIE");
  zlog_info(c, "INFO INFO INFO");
  zlog_debug(c, "DEBUG DEBUG DEBUG");
}

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

  printf("init level:\n");
  print_levels(c);
  print_logs(c);

  zlog_level_switch(c, ZLOG_LEVEL_WARNING);
  printf("\nafter switch to warning: \n--------\n");
  print_levels(c);
  print_logs(c);

  zlog_fini();

  return 0;
}