#include <stdio.h>

// pass a copy of caller's j into function
// i is a local variable, whose changes
// are not reflected in the caller
// "pass by value"
void by_value(int i) {
    i = i * 2;
}

// Passing a pointer (or reference) to an integer
// means we change the value in the caller
void by_reference(int *pi) {
    *pi = *pi * 2;
}

void print_arr(int arr[3]) {
    for (int idx = 0; idx < 3; idx++) {
        printf("arr[%d] = %d\n", idx, arr[idx]);
    }
}

int main(int argc, char *argv[]) {

    int arr[3] = {2, 4, 6};
    for (int idx = 0; idx < 3; idx++) {
        by_value(arr[idx]);
    }
    print_arr(arr);

    for (int idx = 0; idx < 3; idx++) {
        by_reference(&arr[idx]);
    }
    print_arr(arr);

    return 0;
}
