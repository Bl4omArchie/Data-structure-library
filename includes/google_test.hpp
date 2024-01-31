#ifndef GOOGLE_TEST_H
#define GOOGLE_TEST_H

#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <gtest/gtest.h>

#include "file_struct.h"

const uint64_t TEST_DATA_1 = 42;
const uint64_t TEST_DATA_2 = 24;


void setupLinkedList(DoublyLinkedList *linked_list);



#endif