test_inc = include_directories('../src')

tests = [
    'test_tmp',
    'test_longlog',
    'test_buf',
    'test_bitmap',
    'test_conf',
    'test_conf2',
    'test_hashtable',
    'test_hello',
    'test_hex',
    'test_init',
    'test_level',
    'test_leak',
    'test_mdc',
    'test_multithread',
    'test_record',
    'test_pipe',
    'test_press_zlog',
    'test_press_zlog2',
    'test_press_write',
    'test_press_write2',
    'test_press_syslog',
    'test_syslog',
    'test_default',
    'test_profile',
    'test_category',
    'test_prompt',
    'test_enabled',
]

foreach t : tests
    executable(t, files(t+'.c'),
        include_directories: test_inc,
        link_with: libzlog,
        dependencies: thread,
    )
endforeach

mycp = find_program('cpconf.sh')
run_target('cpconf',
    command: [mycp, meson.current_source_dir(), meson.current_build_dir()]
)

custom_target('cpconf2',
    output : 'fake',
    command: [mycp, meson.current_source_dir(), meson.current_build_dir()],
    build_by_default : true
)
