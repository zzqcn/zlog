project('zlog', 'c',
    version: '1.2.12'
)

ver = meson.project_version().split('.')
major_ver = '@0@.@1@'.format(ver.get(0), ver.get(1))
so_ver = ver.get(0)
headers = []
libs = []

thread = dependency('threads')

subdir('src')
if get_option('test')
    subdir('test')
endif
if get_option('doc')
    subdir('doc')
endif


# install headers & libraries
install_headers(headers)
pkg = import('pkgconfig')
pkg.generate(name: 'zlog',
    filebase: 'libzlog',
    version: meson.project_version(),
    description: '''A reliable, high-performance, thread safe, 
flexsible, clear-model, pure C logging library.''',
    #subdirs: ['zlog', '.'],
    libraries: ['-Wl,--as-needed'] + libs,
    #libraries_private: hq_extra_ldflags
)
