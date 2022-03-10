lib_sources = files(
    'buf.c',
    'category_table.c',
    'category.c',
    'conf.c',
    'conf.c',
    'event.c',
    'format.c',
    'level.c',
    'level_list.c',
    'mdc.c',
    'record.c',
    'record_table.c',
    'rotater.c',
    'rule.c',
    'spec.c',
    'thread.c',
    'zc_arraylist.c',
    'zc_hashtable.c',
    'zc_profile.c',
    'zc_util.c',
    'zlog.c',
)

libzlog = shared_library('zlog', lib_sources,
    include_directories: global_inc,
    dependencies: [thread],
    version: major_ver,
    soversion: so_ver,
    install: true,
)

headers += files('zlog.h')
libs += libzlog

executable('zlog-chk-conf', files('zlog-chk-conf.c'),
    include_directories: global_inc,
    link_with: libzlog,
    #dependencies: thread,
    install: true,
)
