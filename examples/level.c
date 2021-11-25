#include <stdio.h>
#include "zlog.h"
#include "category.h"

// if zlog.conf in /etc, you may need superuser privilege to run this demo
#define CONF_FILE_PATH "./zlog.conf"

void print_levels(zlog_category_t *zc)
{
#ifndef ZZQ_LEVEL
    int i;
    printf("fatal: %d, error: %d, warn: %d, notice: %d, info: %d, debug: %d\n",
           zlog_level_enabled(zc, ZLOG_LEVEL_FATAL),
           zlog_level_enabled(zc, ZLOG_LEVEL_ERROR),
           zlog_level_enabled(zc, ZLOG_LEVEL_WARN),
           zlog_level_enabled(zc, ZLOG_LEVEL_NOTICE),
           zlog_level_enabled(zc, ZLOG_LEVEL_INFO),
           zlog_level_enabled(zc, ZLOG_LEVEL_DEBUG));

    printf("level bitmap:\n");
    for (i = 0; i < 32; i++)
    {
        if ((i + 1) % 8 == 0)
            printf("%02d ", i + 1);
        else
            printf("   ");
    }
    printf("\n");
    for (i = 0; i < 32; i++)
        printf("%.2X ", zc->level_bitmap[i]);
#else
    printf("fatal: %d, alert: %d, crit: %d, err: %d, warning: %d, notice: %d, info: %d, debug: %d\n",
           zlog_level_enabled(zc, ZLOG_LEVEL_FATAL),
           zlog_level_enabled(zc, ZLOG_LEVEL_ALERT),
           zlog_level_enabled(zc, ZLOG_LEVEL_CRIT),
           zlog_level_enabled(zc, ZLOG_LEVEL_ERR),
           zlog_level_enabled(zc, ZLOG_LEVEL_WARNING),
           zlog_level_enabled(zc, ZLOG_LEVEL_NOTICE),
           zlog_level_enabled(zc, ZLOG_LEVEL_INFO),
           zlog_level_enabled(zc, ZLOG_LEVEL_DEBUG));
#endif

    printf("\n");
}

int main(int argc, char **argv)
{
    int rc;
    zlog_category_t *c;

    if (argc < 2)
        rc = zlog_init("./zlog.conf");
    else
        rc = zlog_init(argv[1]);
    if (rc)
    {
        printf("init failed\n");
        return -1;
    }

    c = zlog_get_category("my_cat");
    if (!c)
    {
        printf("get cat fail\n");
        zlog_fini();
        return -2;
    }

    printf("init level:\n");
    print_levels(c);

    zlog_info(c, "hello, zlog");

#ifndef ZZQ_LEVEL
    zlog_level_switch(c, ZLOG_LEVEL_WARN);
    printf("after switch to warn: \n");
#else
    zlog_level_switch(c, ZLOG_LEVEL_WARNING);
    printf("after switch to warning: \n");
#endif
    print_levels(c);

    zlog_info(c, "hello, zlog");

    zlog_fini();

    return 0;
}