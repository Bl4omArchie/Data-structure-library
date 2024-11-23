#include "benchmark.h"
#include <sys/time.h>



bench *bench_dll_insertion_tail(int round, int iter) {
    bench *b = create_bench();
    bench_ctx *b_ctx = create_bench_ctx();

    

    start_bench(b_ctx);

    for (int r=0; r<round; r++) {
        dll_node *node = new_dll(50);
        for (int i=0; i<iter; i++)
            dll_insert_value_head(node, generate_random_number());
        dll_free(node);
    }
    end_bench(b, b_ctx);

    create_log(b, "benchmark insertion");

    free(b_ctx);
    return b;
}

bench *bench_dll_insertion_head(int round, int iter) {
    bench *b = create_bench();
    bench_ctx *b_ctx = create_bench_ctx();

    start_bench(b_ctx);

    for (int r=0; r<round; r++) {
        dll_node *node = new_dll(50);
        for (int i=0; i<iter; i++)
            dll_insert_value_head(node, generate_random_number());
        dll_free(node);
    }
    end_bench(b, b_ctx);

    create_log(b, "benchmark insertion");

    free(b_ctx);
    return b;
}