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
    FILE *f = fopen(fname, "w");
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


ruct customer {
    char name[32];
    int age;
};

// pc is a pointer to a struct customer
// we call this "pass by reference"
void print_customer(struct customer *pc) {
    // When we have a pointer to something, we dereference
    // the member of the struct using the -> "points to" operator
    printf("customer name: %s age: %d\n", pc->name, pc->age);
    pc->age = 60;
}
