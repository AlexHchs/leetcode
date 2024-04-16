#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

#define EMPTY (-1)
#define INT_MIN (-2147483648)
#define STACK_EMPTY INT_MIN

typedef struct node{
    int val;
    struct node *next;
}node;

node* head = NULL;

bool push(int val){
    node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> val = val;
    newNode -> next = head;
    head = newNode;

    return true;
}

int pop(){
    if(head == NULL){
        return STACK_EMPTY;
    }

    int result = head -> val;
    node* temp = head;
    head = head -> next;
    free(temp);

    return result;
}

int main(){
    for(int i=1; i<5; i++){
        push(i);
    }

    printf("Stack after push: ");
    node* temp = head;
    while(temp != NULL){
        printf("%d ", temp -> val);
        temp = temp -> next;
    }

    printf("\nStack pop one element then push 5 into stack: ");
    while(head != NULL){
        pop();
    }
    push(5);
    temp = head;
    while(temp != NULL){
        printf("%d ", temp -> val);
        temp = temp -> next;
    }

    return 0;
}