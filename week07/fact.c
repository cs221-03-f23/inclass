#include <stdio.h>
#include <stdlib.h>

int fact_iterative(int n) {
    int result = 1;
    for (int i = n; i >= 1; i--) {
        result = result * i;
    }
    return result;
}

int fact_recursive(int n) {
    if (n == 1) {
        return n;
    } else {
        return n * fact_recursive(n - 1);
    }
}

int main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    if (argc < 2) {
        printf("usage: fact <number>\n");
        exit(-1);
    }
    printf("%d\n", fact_iterative(n));
    printf("%d\n", fact_recursive(n));
}
