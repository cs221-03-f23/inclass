// <> for "system" headers
#include <stdio.h>

// double quotes for headers in our program
#include "stuff.h"

int main(int argc, char *argv[]) {
    for (int i = 0; i < 3; i++) {
        printf("stuff[%d] = %s\n", i, stuff[i]);
    }
}
