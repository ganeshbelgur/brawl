# Copyright 2024-2025 Ganesh Belgur Ramachandra. All Rights Reserved.
#
# MIT License
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

project(
  'brawl',
  ['cpp'],
  license : 'MIT',
  meson_version : '>= 1.1.0',
  default_options : [
    'buildtype=debug',
    'cpp_std=c++14',
  ],
)

cpp = meson.get_compiler('cpp')

project_test_files = [
  'solutions/leetcode/2-add-two-numbers.cpp',
  'solutions/leetcode/3-longest-substring-without-repeating-characters.cpp',
  'solutions/codechef/TSORT.cpp',
]

gtest_dir = 'util/googletest/googletest'
gtest_incdir = include_directories(join_paths(gtest_dir, 'include'), is_system : true)

libgtest = static_library(
  'gtest',
  cpp_args : ['-w'],
  include_directories : [include_directories(gtest_dir), gtest_incdir],
  sources : [
    join_paths(gtest_dir, 'src', 'gtest-all.cc'),
    join_paths(gtest_dir, 'src', 'gtest_main.cc')
  ]
)

gtest_stdio_compare_dir = 'util'

libgtest_stdio_compare = static_library(
  'gtest_stdio_compare',
  cpp_args : ['-w'],
  include_directories: [gtest_stdio_compare_dir, include_directories(gtest_dir), gtest_incdir],
  sources : [
    join_paths(gtest_stdio_compare_dir, 'gtest_stdio_compare.cpp')
  ]
)

test_gtest_stdio_compare_dep = declare_dependency(
  include_directories : gtest_stdio_compare_dir,
  link_with : libgtest_stdio_compare
)

test_gtest_dep = declare_dependency(
  dependencies : dependency('threads'),
  include_directories : gtest_incdir,
  link_with : libgtest
)

# Unit tests
add_languages('cpp', native: false)

fs = import('fs')

foreach source_files : project_test_files
  test_file = fs.stem(source_files)
  is_leetcode = source_files.contains('leetcode')
  is_codechef = source_files.contains('codechef')
  deps = [test_gtest_dep]

  if is_leetcode
    test_folder = 'leetcode'
  elif is_codechef
    test_folder = 'codechef'
    deps += [test_gtest_stdio_compare_dep]
  endif

  test(test_folder + '_' + test_file,
    executable(
      'brawl_' + test_folder + '_' + test_file,
      files(source_files),
      dependencies : [deps],
      install : false
    )
  )
endforeach

