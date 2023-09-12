#include <stdio.h>
#include <string.h>

// Type declaration for "customer"
struct customer {
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

int main(int argc, char *argv[]) {
    int i; // scalar integer
    long l; // long integer

    printf("sizeof(int): %ld\n", sizeof(i));
    printf("sizeof(long): %ld\n", sizeof(l));
    
    int arr[32]; // array of integers

    struct customer c;  // type of c is "struct customer"
    struct customer carr[32]; // type of carr is array of 32 struct customers
    int carr_len = 0; // C arrays don't know their length. So you keep the length

    // sizeof is a compiler intrinsic function
    // C compiler knows how big c.name is
    strncpy(c.name, "Phil", sizeof(c.name));
    c.age = 55;

    print_customer(&c);
    printf("customer name: %s age: %d\n", c.name, c.age);

    printf("sizeof(customer): %ld\n", sizeof(struct customer));
}
