#include <stdio.h>

struct number {
    int i;
    struct number *next;
};

int main(int argc, char *argv[]) {
    struct number num1;
    num1.i = 1;

    struct number num2;
    num2.i = 2;
    num1.next = &num2;

    struct number num3;
    num3.i = 3;
    num2.next = &num3;

    num3.next = NULL;
}
