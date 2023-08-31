#include <stdio.h>

void print_arg_ptr(char s[]) {
    while (*s != '\0') { // check for null
        printf("%c\n", *s); // dereference s
        s++; // pointer arithmetic
    }
}

void print_arg_array(char *s) {
    // strings can be considered as an array
    int index = 0;
    while (s[index] != '\0') {
        printf("%c\n", s[index]);
        index++;
    }
}

int main(int argc, char *argv[]) {
    if (argc >= 2) {
        print_arg_ptr(argv[1]);
    }
}
