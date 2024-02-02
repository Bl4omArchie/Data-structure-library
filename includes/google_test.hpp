#ifndef GOOGLE_TEST_H
#define GOOGLE_TEST_H

#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <random>
#include <gtest/gtest.h>

#include "file_struct.h"

const uint64_t TEST_DATA_1 = 42;
const uint64_t TEST_DATA_2 = 24;

class DoublyLinkedListTest : public ::testing::Test {
    protected:
        DoublyLinkedList linked_list;

        void SetUp() override {
            init_linked_list(&linked_list);
        }
};


#endif