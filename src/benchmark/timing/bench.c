#include "benchmark.h"




bench *create_bench() {
    bench *b = (bench *)malloc(sizeof(bench));
    b->cpu_time = 0.0;
    b->ram = 0.0;
    b->time = 0.0;
    return b;
}

bench_ctx *create_bench_ctx() {
    bench_ctx *b_ctx = (bench_ctx *)malloc(sizeof(bench_ctx));

    b_ctx->start = (struct timeval){0};
    b_ctx->end = (struct timeval){0};
    b_ctx->c_start = 0;
    b_ctx->c_end = 0;
    b_ctx->ram_before = 0;
    b_ctx->ram_after = 0;

    return b_ctx;
}

void start_bench(bench_ctx *b_ctx) {
    gettimeofday(&b_ctx->start, NULL);
    b_ctx->c_start = clock();
    b_ctx->ram_before = get_available_ram();
}

void end_bench(bench *b, bench_ctx *b_ctx) {
    b_ctx->ram_after = get_available_ram();
    b_ctx->c_end = clock();
    gettimeofday(&b_ctx->end, NULL);

    b->time = (b_ctx->end.tv_sec - b_ctx->start.tv_sec) + (b_ctx->end.tv_usec - b_ctx->start.tv_usec) / 1000000.0;
    b->cpu_time = ((double)(b_ctx->c_end - b_ctx->c_start)) / CLOCKS_PER_SEC;
    b->ram = b_ctx->ram_before - b_ctx->ram_after;
}