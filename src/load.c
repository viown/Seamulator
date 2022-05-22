#include "load.h"
#include "memory.h"
#include <stdio.h>
#include <string.h>
#ifdef __linux__
#include <sys/stat.h>
#endif // __linux__

long get_file_size(const char* path) {
#ifdef __linux__
    struct stat st;
    stat(path, &st);
    return st.st_size;
#else
    FILE *file = fopen(path, "r");
    long size;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    fclose(file);
    return size;
#endif
}

void load_rom(const char* path) {
    memset(cartridge, 0, 0x8000);
    long file_size = get_file_size(path);
    if (file_size > 0x8000) {
        return; // 32kb+ not supported
    }
    FILE* file = fopen(path, "r");
    fread(cartridge, 1, file_size, file);
    fclose(file);
}