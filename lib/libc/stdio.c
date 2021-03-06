#include "libc.h"

inline size_t toBytes(ssize_t result) {
    return result >= 0 ? (size_t)result : 0;
}

inline int fileno(FILE* stream) {
    return (int)(intptr_t)stream;
}

FILE* fopen(const char* filename, const char* mode) {
    assert(mode[0] == 'r' && mode[1] == '\0');
    return (FILE*)(intptr_t)open(filename, O_RDONLY);
}

int fclose(FILE *stream) {
    return close(fileno(stream));
}

size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    return toBytes(read(fileno(stream), ptr, nmemb * size));
}

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return toBytes(write(fileno(stream), ptr, nmemb * size));
}

int fputs(const char* str, FILE* stream) {
    return (int)fwrite(str, sizeof(char), strlen(str), stream);
}

int putchar(int c) {
    unsigned char ch = (unsigned char)c;
    return fwrite(&ch, 1, 1, stdout) == 1 ? c : EOF;
}

void setbuf(FILE* stream, char* buffer) {
    assert(stream != NULL && buffer == NULL);
}

/*
int fflush(FILE* stream) {
    return fsync(fileno(stream));
}
*/
