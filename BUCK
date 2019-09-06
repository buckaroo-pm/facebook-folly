load('//:buckaroo_macros.bzl', 'buckaroo_deps')
load('//:subdir_glob.bzl', 'subdir_glob')

cxx_library(
  name = 'folly',
  header_namespace = '',
  exported_headers = subdir_glob([
    ('', 'folly/**/*.h'),
  ], exclude = glob([
    'folly/**/test/**/*.h',
  ])),
  srcs = glob([
    'folly/**/*.cpp',
  ], exclude = glob([
    'folly/**/benchmarks/**/*.cpp',
    'folly/**/exercises/**/*.cpp',
    'folly/**/experimental/**/*.cpp',
    'folly/**/examples/**/*.cpp',
    'folly/**/fibers/**/*.cpp',
    'folly/**/test/**/*.cpp',
    'folly/SingletonThreadLocal.cpp',
    'folly/experimental/JSONSchemaTester.cpp',
    'folly/experimental/io/HugePageUtil.cpp',
    'folly/python/fibers.cpp',
    'folly/python/GILAwareManualExecutor.cpp',
  ])),
  deps = [ x for x in buckaroo_deps() if not ('googletest' in x) ],
  visibility = [
    'PUBLIC',
  ],
)
