#include <stdio.h>
#include <string.h>

// Use preprocessor to substitute 32 for MAX_BUF everywhere
// it occurs in code
#define MAX_BUF 32

// Always use memory-safe versions of strncat, strncpy, snprintf...
// Buffer overflows are the root of many security problems
// due to memory corruption

int main(int argc, char *argv[]) {
    char buf[MAX_BUF];

    // copy bytes from "foobar" into buf
    // which is a local variable on the stack
    strncpy(buf, "foobar ", MAX_BUF);
    printf("buf: %s\n", buf);

    // a C version of "foobar" + "fulton"
    strncat(buf, "fulton", MAX_BUF - strlen(buf) + 1);
    printf("buf: %s\n", buf);

    // i.e. s1 == s2, expecting byte for byte compare
    // In C we use strncmp() to do byte for byte compare
    // s2 == s1 compares pointer values, not string contents
    int cmp = strncmp(buf, "foobar fulton", MAX_BUF);
    printf("cmp: %d\n", cmp);

    if (!strncmp(buf, "foobar fulton", MAX_BUF)) {
        printf("equal\n");
    } else {
        printf("not equal\n");
    }
}
