#include "util.h"


int check_file_exists(const char* filename) {
    struct stat buffer;
    return !stat(filename, &buffer);
}