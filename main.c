#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    struct node *prev;
    struct node *next;
    long value;
} Node;

Node *createNode(long val) {
    Node *top = (Node *)malloc(sizeof(Node));
    top->next = NULL;
    top->prev = NULL;
    top->value = 0;

    Node *old = top;
    
    long temp = 0;
    long firstNumber = 0;
    long secondNumber = 1;
    for(long i = 1; i < val; i++) {
        if(i == 1) {
            Node *first = (Node *)malloc(sizeof(Node));
            first->prev = old;
            first->next = NULL;
            first->value = 1;
            old->next = first;
            old = first;
        } else {
            Node *item = (Node *)malloc(sizeof(Node));
            item->next = NULL;
            item->prev = old;
            item->value = firstNumber + secondNumber;
    
            temp = firstNumber;
            firstNumber = secondNumber;
            secondNumber = temp + secondNumber;
    
            old->next = item;
            old = item;
        }
    }

    return top;
}

void printList(Node *head) {
    while (head != NULL) {
        if(head->next == NULL) {
            //printf("Last value: %ld\n", head->value);
        }
        printf("Value: %ld\n", head->value);
        head = head->next;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    long number = atol(argv[1]);
    printf("Number: %ld\n", number);
    printf("\n");

    Node *head = createNode(number);
    printList(head);

    Node *temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}