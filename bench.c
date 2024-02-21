#include "includes/benchmark.h"
#include "includes/file_struct.h"




int main(int argc, char *argv[]) {
    srand((unsigned int)time(NULL));

    DLL myList;
    init_linked_list(&myList);
    set_data(&myList, generateRandom64BitNumber());

    argc = 2;
    argv[argc] = &myList, generateRandom64BitNumber();
    benchmark(&insert_data_tail, 1000, argc, &argv);

    return 1;
}