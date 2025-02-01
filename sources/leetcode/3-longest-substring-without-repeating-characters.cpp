/* Copyright 2024-2025 Ganesh Belgur Ramachandra. All Rights Reserved.

MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#include <iostream>
#include <cstring>

#include <gtest/gtest.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if (!s.length())
        return 0;

    bool ascii[256];
    for (int i = 0; i < 256; ++i) {
        ascii[i] = false;
    }

    const char* arr = s.c_str();
    int c_ptr = 0;
    int s_ptr = 0;
    int running_max = 0;
    int max = 1;

    while (*(arr + c_ptr) != '\0') {
        const char c = *(arr + c_ptr);
        int ascii_index = int(c);

        if (!ascii[ascii_index]) {
            running_max++;
        } else {
	    max = (running_max > max ? running_max : max);

	    while(true) {
		const char nc = *(arr + s_ptr);
		int n_ascii_index = int(nc);

		s_ptr++;

	        if (n_ascii_index == ascii_index) {   
		    break;
		}

		ascii[n_ascii_index] = false;
		running_max--;
	    }
	}

	ascii[ascii_index] = true;
	c_ptr++;
    }

    max = (running_max > max ? running_max : max);
    return max;
}

TEST(TestLongestSubStringWithoutRepeat, TestCase1) {
    string s = "abcabcbb";
    EXPECT_EQ(3, lengthOfLongestSubstring(s));
}

TEST(TestLongestSubStringWithoutRepeat, TestCase2) {
    string s = "bbbbb";
    EXPECT_EQ(1, lengthOfLongestSubstring(s));
}

TEST(TestLongestSubStringWithoutRepeat, TestCase3) {
    string s = "pwwkew";
    EXPECT_EQ(3, lengthOfLongestSubstring(s));
}
