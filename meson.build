project('zlog', 'c',
    version: run_command(find_program('cat', 'more'),
        files('VERSION')).stdout().strip(),
)

if get_option('buildtype').startswith('debug')
    add_project_arguments('-DDEBUG', language: 'c')
endif
add_project_arguments('-include', 'version.h', language: 'c')

ver = meson.project_version().split('.')
major_ver = '@0@.@1@'.format(ver.get(0), ver.get(1))
so_ver = ver.get(0)
global_inc = include_directories(
    '.'
)
headers = []
libs = []

# 生成version.h
zlog_conf = configuration_data()
zlog_conf.set_quoted('ZLOG_VERSION', meson.project_version())
configure_file(
    output: 'version.h',
    configuration: zlog_conf,
    install: false,
)

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
