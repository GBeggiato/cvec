/* 
 * some nice strings in C
 *
 * thanks to Tsoding (https://www.youtube.com/@Tsoding)
*/ 

#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================================================================

#define STR_INITIAL_CAPACITY 256

typedef struct {
    char *str;
    size_t length;
    size_t capacity;
} String_Builder;

void str_reserve(String_Builder *sb, size_t new_cap) {
    if (new_cap <= sb->capacity) return;
    if (sb->capacity == 0) sb->capacity = STR_INITIAL_CAPACITY;
    while (new_cap > sb->capacity) sb->capacity *= 2;
    sb->str = realloc(sb->str, sb->capacity * sizeof(char *));
    assert(sb->str != NULL && "bad str realloc");
}

void str_push(String_Builder *sb, char *cstr) {
    size_t n = strlen(cstr);
    str_reserve(sb, sb->length + n);
    memcpy(sb->str + sb->length, cstr, n * sizeof(char *));
    sb->length += n;
}

void str_free(String_Builder *sb) {
    free(sb->str);
}

void str_reset(String_Builder *sb) {
    sb->capacity = 0;
    sb->length = 0;
    str_free(sb);
    str_reserve(sb, STR_INITIAL_CAPACITY);
}

// ============================================================================

#define SHORT_STRING_CAP 64

static inline void assert_snprintf(int r) {
    assert(r >= 0 && r+1 < SHORT_STRING_CAP);
}

typedef struct {
    char str[SHORT_STRING_CAP];
} Short_String;

Short_String sstrf(const char *fmt, ...) {
    Short_String ss = {0};
    va_list args;
    va_start(args, fmt);
    int r = vsnprintf(ss.str, SHORT_STRING_CAP, fmt, args);
    assert_snprintf(r);
    va_end(args);
    return ss;
}

Short_String sstr_fromcstr(char *str) {
    Short_String ss = {0};
    int r = snprintf(ss.str, SHORT_STRING_CAP, "%s", str);
    assert_snprintf(r);
    return ss;
}


// ============================================================================

int main() {
    {
        String_Builder sb = {0};
        int i = 1;
        str_push(&sb, "hello");
        printf("%d | %s\n", i, sb.str); i++;
        str_push(&sb, " world");
        printf("%d | %s\n", i, sb.str); i++;
        str_reset(&sb);
        printf("%d | %s (garbage here)\n", i, sb.str); i++;
        str_push(&sb, "world hello");
        printf("%d | %s\n", i, sb.str); i++;
    }
    printf("=============================\n");
    {
        Short_String ss = sstr_fromcstr("hello, man");
        printf("%s\n", ss.str);
        Short_String sf = sstrf("%d.%d\n", 1, 22);
        printf("%s\n", sf.str);
    }
}

