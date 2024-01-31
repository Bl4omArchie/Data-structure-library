#include "../includes/google_test.hpp"


class DoublyLinkedListTest : public ::testing::Test {
    protected:
        DoublyLinkedList linked_list;

        void SetUp() override {
            init_linked_list(&linked_list);
        }
};


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