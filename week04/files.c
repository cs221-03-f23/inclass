#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 32

struct Person {
    char name[MAX_NAME];
    char address[64];
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("invalid arguments\n");
        exit(-1);
    }

    char *fname = argv[1];
    FILE *f = fopen(fname, "wb");
    if (!f) {
        printf("fopen failed\n");
        exit(-1);
    }

    struct Person p;
    strncpy(p.name, "John Smith", MAX_NAME);
    p.name[0] = 'x';
    strncpy(p.address, "123 Main St.", sizeof(p.address));

    int nwritten = fwrite(&p, sizeof(struct Person), 1, f);
    if (nwritten != 1) {
        printf("fwrite failed\n");
        exit(-1);
    }

    fclose(f);
}
