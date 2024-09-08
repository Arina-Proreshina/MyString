#include <stddef.h>
#include <assert.h>
#include <ctype.h>
#include "mystring.h"

size_t myStrlen(const char* str) {
    assert(str != NULL);
    size_t len = 0;
    while (*str++) len++;
    return len;
}

char* myStrcpy(char* dst, const char* src) {
    assert(dst != NULL && src != NULL);
    char* start = dst;
    while (*src) {
        *dst++ = *src++;
    }
    *dst = '\0';
    return start;
}

char* myStrconn(char* dst, const char* src) {
    assert(dst != NULL && src != NULL);
    char* start = dst + myStrlen(dst);
    myStrcpy(start, src);
    return dst;
}

char* myStrchr(const char* str, int c) {
    assert(str != NULL);
    while (*str) {
        if (*str == (char)c) {
            return (char*)str;
        }
        str++;
    }
    return NULL;
}

char* myStrtok(char* str, const char* delim) {
    static char* last;
    assert(delim != NULL);
    if (str) last = str;
    if (!last || *last == '\0') return NULL;
    while (*last && myStrchr(delim, *last)) last++;
    if (*last == '\0') return NULL;
    char* start = last;
    while (*last && !myStrchr(delim, *last)) last++;
    if (*last) *last++ = '\0';
    return start;
}

int myStrcmp(const char* str1, const char* str2) {
    assert(str1 != NULL && str2 != NULL);

    while (*str1 == ' ') {
        str1++;
    }
    while (*str2 == ' ') {
        str2++;
    }

    while (*str1 && (tolower((unsigned char)*str1) == tolower((unsigned char)*str2))) {
        str1++;
        str2++;
    }

    return (unsigned char)tolower(*str1) - (unsigned char)tolower(*str2);
}
