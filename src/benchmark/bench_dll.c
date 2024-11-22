#include "benchmark.h"
#include <sys/time.h>



bench *bench_dll_insertion() {
    bench *b = create_bench();
    bench_ctx *b_ctx = create_bench_ctx();

    dll_node *node = new_dll(50);

    start_bench(b_ctx);

    for (int i=0; i<50000000; i++) {
        dll_insert_value_tail(node, generate_random_number());
    }

    dll_free(node);

    end_bench(b, b_ctx);
    free(b_ctx);
    return b;
}



int bench_dll_minimal() {

}

int bench_dll_medium() {

}

int bench_dll_maximal() {

}