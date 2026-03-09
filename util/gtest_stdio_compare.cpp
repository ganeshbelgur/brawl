#include "gtest_stdio_compare.h"

void gtest_stdio_compare(const std::string& input, const std::string& expected, int (*test_func)()) {
    std::stringstream ss(input);

    // Save original cin buffer
    std::streambuf* old_cin_buf = std::cin.rdbuf();

    // Redirect std::cin to the stringstream
    // Only works if the test functions uses std::cout and std::cin
    // Does not work with scanf() and printf()
    std::cin.rdbuf(ss.rdbuf());

    // Start stdout capture
    testing::internal::CaptureStdout();

    // Call the function under test
    test_func();

    // Stop stdout capture and fetch the output
    std::string output = testing::internal::GetCapturedStdout();

    // Compare results
    EXPECT_EQ(expected, output);

    // Restore original cin buffer
    std::cin.rdbuf(old_cin_buf);
}
