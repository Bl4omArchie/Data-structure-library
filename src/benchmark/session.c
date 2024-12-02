#include "benchmark.h"



session *init_session(int round, int iteration, const char *op) {
    session *s = (session*)malloc(sizeof(session*));
    s->size_bench_ctx = 0;
    s->operation = op;
    s->N = round;
    s->X = iteration;

    return s;
}


bctx *init_record() {
    bctx *bench_ctx = (bctx*)malloc(sizeof(bctx));

    bench_ctx->start = (struct timeval){0};
    bench_ctx->end = (struct timeval){0};
    bench_ctx->c_start = 0;
    bench_ctx->c_end = 0;
    bench_ctx->ram_before = 0;
    bench_ctx->ram_after = 0;

    return bench_ctx;
}

int add_bench(session *s, benchmark *b) {
    if (s == NULL || b == NULL)
        return -1;
    return 1;
}

void start_record(bctx *bench_ctx) {
    gettimeofday(bench_ctx->start, NULL);
    bench_ctx->c_start = clock();
    bench_ctx->ram_before = get_available_ram();
}

void end_record(bctx *bench_ctx) {
    gettimeofday(&b->bctx->end, NULL);
    bench_ctx->ram_after = get_available_ram();
    bench_ctx->c_end = clock();

    /*
        b->time = (b->bctx->end.tv_sec - b->bctx->start.tv_sec) + (b->bctx->end.tv_usec - b->bctx->start.tv_usec) / 1000000.0;
    b->cpu_time = ((double)(b->bctx->c_end - b->bctx->c_start)) / CLOCKS_PER_SEC;
    b->ram = b->bctx->ram_before - b->bctx->ram_after;
    */
}

int free_session(session *s) {
    if (s == NULL)
        return -1;

    free(bs->bench_ctx);
    free(s);
    return 1;
}