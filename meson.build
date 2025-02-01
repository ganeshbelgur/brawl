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
  'sources/leetcode/2-add-two-numbers.cpp',
  'sources/leetcode/3-longest-substring-without-repeating-characters.cpp',
]

gtest_dir = 'googletest/googletest'
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

test_dep = declare_dependency(
  dependencies : dependency('threads'),
  include_directories : gtest_incdir,
  link_with : libgtest
)

# Unit tests
add_languages('cpp', native: false)

test('all_tests',
  executable(
    'brawls',
    files(project_test_files),
    dependencies : [test_dep],
    install : false
  )
)
