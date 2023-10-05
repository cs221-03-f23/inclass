#include <stdio.h>
#include <stdlib.h>

int sum_iterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int sum_recursive(int n) {
    // base case
    if (n == 1) {
        return n;
        // recursive case
    } else {
        return n + sum_recursive(n - 1);
    }
}

int main(int argc, char *argv[]) {
    // usage: ./a.out 10
    // 55
    if (argc < 2) {
        printf("usage: ./a.out <number>\n");
        exit(-1);
    }

    int n = atoi(argv[1]);
    // using iterative function
    printf("%d\n", sum_iterative(n));
    // using recursive function
    printf("%d\n", sum_recursive(n));
}
