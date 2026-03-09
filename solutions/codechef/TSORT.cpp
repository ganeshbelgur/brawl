#include "util/gtest_stdio_compare.h"

int main_TSORT() {
    int i, size, n, j;
    int A[1000000] = {0};

    std::cin >> size;

    for(i = 0; i < size; i++) {
	std::cin >> n;
        ++A[n - 1];
    }

    for(i = 0; i < 1000000; i++) {
        // Using loop here to handle duplicate values
        for (j = 0; j < A[i]; j++) {
	    std::cout << i + 1 << std::endl;
        }
    }

    return 0;
}

TEST(TSORT, Sample1TestCase) {
    std::string input =
R"(5
5
3
6
7
1
)";

    std::string expected =
R"(1
3
5
6
7
)";

    gtest_stdio_compare(input, expected, main_TSORT);
}

TEST(TSORT, RandomTestCase) {
    std::string input =
R"(13
999
998
344
531
1
2
3
4
5
6
7
565
44
)";

    std::string expected =
R"(1
2
3
4
5
6
7
44
344
531
565
998
999
)";

    gtest_stdio_compare(input, expected, main_TSORT);
}

