#include "benchmark.h"

/*
benchmark *bench_dll_insertion_tail(int round, int iter) {
    bench *b = create_bench();

    start_record(b);

    for (int r=0; r<round; r++) {
        dll_node *node = new_dll(50);
        for (int i=0; i<iter; i++)
            dll_insert_value_head(node, generate_random_number());
        dll_free(node);
    }
    end_record(b);
    return b;
}

benchmark *bench_dll_insertion_head(int round, int iter) {
    bench *b = create_bench();

    start_record(b);

    for (int r=0; r<round; r++) {
        dll_node *node = new_dll(50);
        for (int i=0; i<iter; i++)
            dll_insert_value_head(node, generate_random_number());
        dll_free(node);
    }
    end_record(b);
    return b;
}

*/