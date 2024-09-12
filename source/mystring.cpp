#include <stddef.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include "../include/mystring.h"

size_t myStrlen(const char* str) {
    assert(str != NULL);
    size_t len = 0;

    while (*str++) {
        len++;
    }

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

char* myStrncpy(char *dst, const char *src, size_t n) {
    assert(dst != NULL && src != NULL && n != NULL);
    char *start = dst;

    while (n && (*dst++ = *src++)) {
        n--;
    }

    while (n--) {
        *dst++ = '\0';
    }

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
    if (str)
        last = str;

    if (!last || *last == '\0')
        return NULL;

    while (*last && myStrchr(delim, *last))
        last++;

    if (*last == '\0')
        return NULL;

    char* start = last;

    while (*last && !myStrchr(delim, *last))
        last++;

    if (*last) {
        *last = '\0';
        last++;
    }

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

    while (*str1 && *str2 && (tolower((unsigned char)*str1) == tolower((unsigned char)*str2))) {
        str1++;
        str2++;
    }

    return (unsigned char)tolower(*str1) - (unsigned char)tolower(*str2);
}

int myPuts(const char *str) {
    assert(str != NULL);

    if (!str) {
        return EOF;
    }

    while (*str) {
        if (putchar(*str++) == EOF) {
            return EOF;
        }
    }

    if (putchar('\n') == EOF) {
        return EOF;
    }

    return 0;
}


char* myStrcut(char *str, int c) {
    assert(str != NULL);
    char *pos = myStrchr(str, c);

    if (pos) {
        *pos = '\0';
    }

    return str;
}

char* myStrncut(char *str, size_t n) {
    assert(str != NULL);

    if (n < myStrlen(str)) {
        str[n] = '\0';
    }

    return str;
}

char* myFgets(char *str, int n, FILE *stream) {
    assert(str != NULL);
    int c, i = 0;

    while (i < n - 1 && (c = fgetc(stream)) != EOF) {
        str[i++] = (char)c;
        if (c == '\n') break;
    }

    str[i] = '\0';
    return (i == 0 && c == EOF) ? NULL : str;
}

char* myStrdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    size_t size = myStrlen(str) + 1;
    char *dup = (char *) calloc(size, sizeof(char));

    if (dup == NULL) {
        return NULL;
    }

    myStrcpy(dup, str);

    return dup;
}

size_t myGetlen(const char *str, size_t max_len) {
    assert(str != NULL);
    size_t len = 0;

    while (len < max_len && *str++) {
        len++;
    }

    return len;
}
