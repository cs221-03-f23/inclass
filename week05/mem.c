struct foo {
    int i;
};

struct foo *make_foo() {
    // With malloc, you can allocate a block and 
    // return it from a function, which would not be legal
    // if the struct foo were on the stack
    
    // struct foo f;
    // return &f; //boom!
    
    struct foo *pf = malloc(sizeof(struct foo));
    return pf;
}

int main(int argc, char *argv[]) {
    struct foo *pf = make_foo();
    pf->i = 0; // dereference pf to get to the i attrib

    struct foo f;
    f.i = 1; // use '.' when we have a value, rather than a ref

    // this is wrong since f is a local var on the stack
    //free(f);

    free(pf);
}
