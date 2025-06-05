#include "benchmark.h"



benchmark *start_benchmark() {
    benchmark *b = (benchmark*)malloc(sizeof(benchmark));
    b->arr_sessions = create_session();
    b->size_sessions = 1;
    b->hardware_profile = create_hardware_profile();
    b->file_log = LOG_FILE;
    b->file_report = REPORT_FILE;
    return b;
}

int end_benchmark(benchmark *b) {
    if (b == NULL)
        return -1;

    free(b->arr_sessions);
    free(b);
    return 1;
}

int add_session(benchmark *b, session *s) {
    if (b == NULL || s == NULL)
        return -1; 
    return 1;
}

int check_file_exists(const char* filename) {
    struct stat buffer;
    return !stat(filename, &buffer);
}

int modify_log_file(benchmark *b, const char *filepath) {
    if (b == NULL)
        return -1;

    if (check_file_exists(filepath)) {
        b->file_log = filepath;
        return 1;
    }
    return -1;
}

int modify_report_file(benchmark *b, const char *filepath) {
    if (b == NULL)
        return -1;
        
    if (check_file_exists(filepath)) {
        b->file_report = filepath;
        return 1;
    }
    return -1;
}
