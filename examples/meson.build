project('zlog_example', 'c')

zlog = dependency('libzlog', required: true)

src_inc = include_directories('../src')

executable('hello', 'hello.c',
    dependencies: [zlog],
)

executable('level', 'level.c',
    include_directories: src_inc,
    dependencies: [zlog],
)
