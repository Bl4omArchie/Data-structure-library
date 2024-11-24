#include "session.h"





b_session *start_benchmark_session() {
    bench *b = create_bench();
    hprof *hp = create_hardware_profile();
    b_session *bs = (b_session*)malloc(sizeof(b_session*));
    
    bs->bench_log = b;
    bs->profile = hp;
    bs->log_file = LOG_FILE;
    bs->report_file = REPORT_FILE;
    return bs;
}

void add_bench(b_session *bs) {

}

int modify_log_file(b_session *bs, const char *filepath) {
    if (bs == NULL)
        return -1;

    if (checkIfFileExists(filepath)) {
        bs->log_file = filelength;
        return 1;
    }
    return -1;
}

int modify_report_file(b_session *bs, const char *filepath) {
    if (bs == NULL)
        return -1;
        
    if (checkIfFileExists(filepath)) {
        bs->bench_log = filelength;
        return 1;
    }
    return -1;
}

void end_benchmark_session(b_session *bs) {

}