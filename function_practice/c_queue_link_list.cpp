#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

#define EMPTY (-1)
#define INT_MIN (-2147483648)
#define QUEUE_EMPTY INT_MIN

typedef struct node{
    int val;
    struct node *next;
}node;

node* tail = NULL;

bool push(int val){
    node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> val = val;

    if(tail == NULL){
        tail = newNode;
        tail -> next = newNode;
    }
    else{
        newNode -> next = tail -> next;
        tail -> next = newNode;
        tail = newNode;
    }

    return true;
}

int pop(){
    if(tail == NULL){
        return QUEUE_EMPTY;
    }
    
    int result;
    node *temp = tail -> next;
    result = (tail -> next) -> val;
    tail -> next = (tail -> next) -> next;
    free(temp); 

    return result;
}

int main(){
    for(int i=0; i<5; i++){
        push(i);
    }
    printf("Stack after push: ");
    node* temp = tail -> next;
    for(int i=0; i<5;i++){
        printf("%d ", temp -> val);
        temp = temp -> next;
    }
}