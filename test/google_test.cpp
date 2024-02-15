#include "../includes/google_test.hpp"
 


uint64_t get_random_number() {
    std::random_device rd;
    std::mt19937_64 gen(rd()); // Mersenne Twister 64-bit
    std::uniform_int_distribution<uint64_t> dis;

    return dis(gen);
}


/*
Test routine:
1) init two structs
2) insert elements into head and tails
3) insert values
4) set some values
5) remove somes
6) clear for the first list and free for the second one  
*/

// Test Initialization 
TEST_F(DoublyLinkedListTest, Initialization) {
    ASSERT_EQ(linked_list.data, 0);
    ASSERT_EQ(linked_list.head, nullptr);
    ASSERT_EQ(linked_list.tail, nullptr);
}

// Test Insertion and Display
TEST_F(DoublyLinkedListTest, InsertionAndDisplay) {
    insert_data_tail(&linked_list, 42);
    insert_data_tail(&linked_list, 24);
    insert_data_head(&linked_list, 10);

    testing::internal::CaptureStdout();
    display_linked_list(&linked_list);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "10 <-> 42 <-> 24\n");
}

// Test Deletion
TEST_F(DoublyLinkedListTest, Deletion) {
    insert_data_tail(&linked_list, 42);
    insert_data_tail(&linked_list, 24);
    insert_data_head(&linked_list, 10);

    DoublyLinkedList *node_to_remove = find_head(&linked_list);
    ASSERT_NE(node_to_remove, nullptr);

    remove_element(node_to_remove);

    testing::internal::CaptureStdout();
    display_linked_list(&linked_list);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "42 <-> 24\n");
}

// Test Clear and Free memory
TEST_F(DoublyLinkedListTest, ClearingAndFreeingMemory) {
    insert_data_tail(&linked_list, 42);
    insert_data_tail(&linked_list, 24);
    insert_data_head(&linked_list, 10);

    clear_linked_list(&linked_list);

    ASSERT_EQ(linked_list.head, nullptr);
    ASSERT_EQ(linked_list.tail, nullptr);

    free_linked_list(&linked_list); // Check for memory leaks
    ASSERT_EQ(linked_list.data, 0);
}