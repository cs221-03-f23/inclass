#include <stdio.h>
#include <stdlib.h>

struct number {
    int i;
    struct number *next;
};

void print_numbers(struct number *head) {
    while (head) {
        printf("num: %d\n", head->i);
        head = head->next;
    }
}

struct number *insert_number(struct number *head, struct number *pnum) {
    if (!head) {
        return pnum;
    }

    struct number *walk = head;
    struct number *prev;
    while (walk) {
        prev = walk;
        walk = walk->next;
    }
    prev->next = pnum;
    return head;
}

void remove_num(struct number *head, int n) {
    struct number *walk = head;
    struct number *prev;

    while (walk->i != n) {
        prev = walk;
        walk = walk->next;
    }
    prev->next = walk->next;
    free(walk);
}

int main(int argc, char *argv[]) {
    struct number *head = NULL;

    for (int i = 1; i < argc; i++) {
        int arg = atoi(argv[i]);

        struct number *pnum = malloc(sizeof(struct number));
        if (!pnum) {
            printf("malloc failed\n");
            exit(-1);
        }

        pnum->i = arg;
        head = insert_number(head, pnum);
    }

    remove_num(head, 44);

    print_numbers(head);
}
