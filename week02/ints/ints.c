#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = 42;

    printf("i: %d\n", i);

    int arr[3] = {2, 4, 6};
    for (int idx = 0; idx < 3; idx++) {
        int j = arr[idx] * 2;
        printf("arr[%d] = %d, j = %d\n", idx, arr[idx], j);
    }

    printf("j: %d\n", j);
    return 0;
}
