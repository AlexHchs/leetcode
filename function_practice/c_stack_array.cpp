#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

#define STACK_LENGTH 5
#define EMPTY (-1)
#define INT_MIN (-2147483648)
#define STACK_EMPTY INT_MIN

int stack[STACK_LENGTH];
int top = EMPTY;

bool push(int val){
    if(top == STACK_LENGTH){
        return false;
    }

    stack[++top] = val;

    return true;
}

int pop(){
    if(top == EMPTY){
        return STACK_EMPTY;
    }

    return stack[top--];
}

int main(){
    printf("Stack after push: ");
    for(int i=0; i<5; i++){
        push(i);
    }
    for(int i=0; i<5; i++){
        printf("%d ", stack[i]);
    }

    printf("\nStack pop all then push 6: ");
    while(top != EMPTY){
        printf("\npop: %d ", pop());
    }
    push(6);
    int temp = top;
    while(temp != EMPTY){
        printf("\n%d", stack[temp]);
        temp--;
    }

    return 0;
}