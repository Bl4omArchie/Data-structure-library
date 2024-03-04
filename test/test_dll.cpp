#include <../includes/google_test.hpp>
 


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

// T.1.1 - Initialization 
TEST_F(DoublyLinkedListTest, Initialization) {
    DLL myList;
    init_linked_list(&myList);

    ASSERT_EQ(myList.data, 0);
    ASSERT_EQ(myList.head, nullptr);
    ASSERT_EQ(myList.tail, nullptr);
}

// T.1.2 and T.1.8 - Insertion and Display
TEST_F(DoublyLinkedListTest, InsertionAndDisplay) {
    DLL myList;
    init_linked_list(&myList);

    insert_data_tail(&myList, 42);
    insert_data_tail(&myList, 24);
    insert_data_head(&myList, 10);

    testing::internal::CaptureStdout();
    display_linked_list(&myList);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "10 <-> 42 <-> 24\n");
}

// T.1.4 - Test Deletion
TEST_F(DoublyLinkedListTest, Deletion) {
    DLL myList;
    init_linked_list(&myList);

    insert_data_tail(&myList, 42);
    insert_data_tail(&myList, 24);
    insert_data_head(&myList, 10);

    DoublyLinkedList *node_to_remove = find_head(&myList);
    ASSERT_NE(node_to_remove, nullptr);

    remove_element(node_to_remove);

    testing::internal::CaptureStdout();
    display_linked_list(&myList);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "42 <-> 24\n");
}

// T.1.5 and T.1.6 - Clear and Free memory
TEST_F(DoublyLinkedListTest, ClearingAndFreeingMemory) {
    DLL myList;
    init_linked_list(&myList);

    insert_data_tail(&myList, 42);
    insert_data_tail(&myList, 24);
    insert_data_head(&myList, 10);

    clear_linked_list(&myList);

    ASSERT_EQ(myList.head, nullptr);
    ASSERT_EQ(myList.tail, nullptr);

    free_linked_list(&myList); // Check for memory leaks
    ASSERT_EQ(myList.data, 0);
}