#include <stdio.h>

void print_string(char *str) {
    printf("the string: %s\n", str);
}

// argc is the count of args from the shell
// argv is an array (or vector) of each of those arguments
// argv elements are C strings
int main(int argc, char *argv[]) {

    char string[10]; // uninitialized memory - could be anything
    strcpy(string, "foobar"); // init mem to "foobar"

    // This is a legal call, even though char* and char s[] 
    // look different. Arrays in C are simply pointers, where
    // the address of the array == address of first element
    print_string(string);

    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
}
