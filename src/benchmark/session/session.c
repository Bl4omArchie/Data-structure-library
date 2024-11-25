#include "session.h"





b_session *start_benchmark_session() {
    b_session *bs = (b_session*)malloc(sizeof(b_session));
    bs->array_bench = create_bench();
    bs->hardware_profile = create_hardware_profile();
    bs->count_bench = 0;
    bs->count_profile = 0;
    bs->file_log = LOG_FILE;
    bs->file_report = REPORT_FILE;
    return bs;
}

int end_benchmark_session(b_session *bs) {
    if (bs == NULL)
        return -1;

    free(bs->array_bench);
    free(bs->hardware_profile);
    free(bs);
    return 1;
}

int add_bench(b_session *bs, bench *b) {
    if (bs == NULL)
        return -1; 


}

int modify_log_file(b_session *bs, const char *filepath) {
    if (bs == NULL)
        return -1;

    if (check_file_exists(filepath)) {
        bs->file_log = filepath;
        return 1;
    }
    return -1;
}

int modify_report_file(b_session *bs, const char *filepath) {
    if (bs == NULL)
        return -1;
        
    if (check_file_exists(filepath)) {
        bs->file_report = filepath;
        return 1;
    }
    return -1;
}