#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

#define STACK_LENGTH 5

bool tag = false;                   // Justify empty(false) or full(true)
int queue[STACK_LENGTH];
int front = 0;
int rear = 0;

bool enqueue(int val){
    if(rear == front && tag == true){
        return tag;
    }
    else{
        rear = (rear + 1) % STACK_LENGTH;
        queue[rear] = val;
        tag = (rear == front) ? true : false;
        return true;
    }
}

int dequeue(){
    if(rear == front && !tag){
        return tag;
    }
    else{
        front = (front + 1) & STACK_LENGTH;
        int result = queue[front];
        queue[front] = -1;
        tag = (rear == front) ? true : false;
        return tag;
    }
}

int main(){
    printf("Queue after push: ");
    for(int i=0; i<5; i++){
        enqueue(i);
    }
    for(int i=front; i<5; i++){
        printf("%d ", queue[(i+1)%5]);
    }

    printf("\nDqueue once: ");
    dequeue();
    enqueue(12);
    for(int i=front; i<6; i++){
        printf("%d ", queue[(i+1)%5]);
    }

    return 0;
}