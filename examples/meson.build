project('zlog_example', 'c')

zlog = dependency('libzlog', required: true)

executable('hello', 'hello.c',
    dependencies: [zlog],
)
