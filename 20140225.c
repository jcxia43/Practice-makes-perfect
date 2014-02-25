#include "stdio.h"
#include "stdlib.h"

// problem: http://chuansongme.com/n/308748
struct SingleList
{
    int value;
    struct SingleList *next;
};

typedef struct SingleList SingleList;

SingleList *generate_list(int n);
SingleList *adder(SingleList *a, SingleList *b);
void print_list(SingleList *head);

int main(int argc, char const *argv[])
{
    SingleList *A, *B;
    int i;
    // generate random 20 cases
    for (i=1; i<=20; ++i)
    {
        A = generate_list(i);
        B = generate_list(i);
        print_list(A);
        printf("+\n");
        print_list(B);
        printf("=\n");
        print_list(adder(A, B));
        printf("---\n");
    }

    return 0;
}
// generate a singly linked list with a fixed length n
// each entry is a random number from 0-9
SingleList *generate_list(int n)
{
    int i;
    SingleList *head = malloc(sizeof(SingleList));
    if (head == NULL) perror("Memory Error!");
    SingleList *p, *t = head;
    head->value = -1;
    head->next = NULL;
    for (i = 0; i < n; ++i)
    {
        p = malloc(sizeof(SingleList));
        if (p == NULL) perror("Memory Error!");
        p->value = rand() % 10;
        // make sure not start with 0
        while (t == head && p->value == 0) p->value = rand() % 10;
        p->next = NULL;
        t->next = p;
        t = p;
    }
    return head;
}

void print_list(SingleList *head)
{
    while (head->next != NULL)
    {
        head = head->next;
        printf("%d", head->value);
    }
    printf("\n");
}

SingleList *adder(SingleList *a, SingleList *b)
{
    SingleList *result = malloc(sizeof(SingleList));
    if (result == NULL) perror("Memory Error");
    int sum;
    // carry position points to the closest entry(not 9) to
    // the current entry
    SingleList *carry_position = result;
    SingleList *allocator, *current = result;
    while (a->next != NULL)
    {
        a = a->next;
        b = b->next;
        sum = a->value + b->value;
        allocator = malloc(sizeof(SingleList));
        if (allocator == NULL) perror("Memory Error");
        allocator->next = NULL;
        current->next = allocator;
        current = allocator;
        if (sum < 10)
        {
            current->value = sum;
            if (sum < 9) carry_position = current;
        }
        else
        {
            current->value = sum - 10;

            if (carry_position != result)
            {
                carry_position->value += 1;
                // set 0 for all 9
                while (carry_position->next != current)
                {
                    carry_position = carry_position->next;
                    carry_position->value = 0;
                }
                carry_position = current;
            }
            else
            // carry on the first entry
            // add a new entry next to the result
            {
                allocator = malloc(sizeof(SingleList));
                if (allocator == NULL) perror("Memory Error");
                allocator->value = 1;
                allocator->next = current;
                result->next = allocator;
                carry_position = current;
            }
        }
    }
    return result;
}
