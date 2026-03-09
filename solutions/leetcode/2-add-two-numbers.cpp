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
#include <gtest/gtest.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *temp_1 = l1;
    ListNode *temp_2 = l2;

    ListNode* head = new ListNode(0);
    ListNode* ptr = head;

    int sum = 0;
    bool carry = false;

    while(true) {
        // Sum up the values from the nodes
        sum += (temp_1 ? temp_1->val : 0);
        sum += (temp_2 ? temp_2->val : 0);

        // Calculate carry, digit
        int digit = ptr->val + sum;
        carry = (digit >= 10);
        digit = (carry ? (digit % 10) : digit);

        ptr->val = digit;

        temp_1 = (temp_1 ? temp_1->next : nullptr);
        temp_2 = (temp_2 ? temp_2->next : nullptr);

        // if we have reached the end of both lists and there is no carry, break
        if (!temp_1 && !temp_2 && !carry)
            break;

        // Create next node
        ptr->next = new ListNode(0);
        ptr = ptr->next;

        if (carry) {
            ptr->val = 1;
            carry = false;
        }

        sum = 0;
    }

    return head;
}

void printList(ListNode* head) {
    ListNode* ptr = head;

    std::cout << "[ ";

    while(ptr) {
        std::cout << ptr->val << " ";
	ptr = ptr->next;
    }

    std::cout << "]" << std::endl;
}

TEST(TestAddTwoNumbers, SimpleCase) {
    ListNode* L1 = new ListNode(9);
    L1->next = new ListNode(9);
    L1->next->next = new ListNode(9);
    L1->next->next->next = new ListNode(9);
    L1->next->next->next->next = new ListNode(9);
    L1->next->next->next->next->next = new ListNode(9);
    L1->next->next->next->next->next->next = new ListNode(9);

    ListNode* L2 = new ListNode(9);
    L2->next = new ListNode(9);
    L2->next->next = new ListNode(9);
    L2->next->next->next = new ListNode(9);

    ListNode* L3 = addTwoNumbers(L1, L2);
    EXPECT_EQ(8, L3->val);
    L3 = L3->next;
    EXPECT_EQ(9, L3->val);
    L3 = L3->next;
    EXPECT_EQ(9, L3->val);
    L3 = L3->next;
    EXPECT_EQ(9, L3->val);
    L3 = L3->next;
    EXPECT_EQ(0, L3->val);
    L3 = L3->next;
    EXPECT_EQ(0, L3->val);
    L3 = L3->next;
    EXPECT_EQ(0, L3->val);
    L3 = L3->next;
    EXPECT_EQ(1, L3->val);
    L3 = L3->next;
    EXPECT_EQ(nullptr, L3);
}
