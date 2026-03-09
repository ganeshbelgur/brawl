# Brawl

All successful submissions for various competitive programming contests and pratice problems. The solutions are packaged into a suite of tests with sample inputs. gtest is the testing framework used.

## Getting Started

To clone the repository along with gtest,

```shell
git clone --recursive git@github.com:ganeshbelgur/brawl.git
```

To build all tests,

```shell
meson setup build
ninja -Cbuild
```

To run the full test suite covering all the problems,

```shell
meson test -Cbuild
```

## Running individual tests

Each problem's test set can be executed independently too.

```shell
./build/brawl_<problem_name>
```

