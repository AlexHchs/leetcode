#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
using namespace std;

#define ARRAY_LENGTH 31
#define NONE_EXIST (-1)
#define INT_MIN (-2147483648)
#define BST_EMPTY INT_MIN

bool empty = true;
// int* array = (int*)malloc(ARRAY_LENGTH*sizeof(int));
int array[ARRAY_LENGTH];

bool insert_bst(int val){
    int index = 0;

    while(index < ARRAY_LENGTH){
        if(array[index] == INT_MIN){
            array[index] = val;
            return true;
        }
        
        if(array[index] >= val){
            index = index * 2 + 1;
        }
        else{
            index = index * 2 + 2;
        }
    }

    return false;
}

int find_node(int val, int index){
    while(index < ARRAY_LENGTH){
        if(array[index] == val){
            return index;
        }
        else if(array[index] > val){
            index = index * 2 + 1;
        }
        else{
            index = index * 2 + 2;
        }
    }

    return NONE_EXIST;
}

int node_degree(int index){
    int left_node, right_node;
    left_node = index * 2 + 1;
    right_node = index * 2 + 2;

    if(left_node >= ARRAY_LENGTH){
        return 0;
    }

    if(array[left_node] == INT_MIN && array[right_node] == INT_MIN){
        return 0;
    }
    else if(array[left_node] != INT_MIN && array[right_node] == INT_MIN){
        return 1;
    }
    else if(array[left_node] == INT_MIN && array[right_node] != INT_MIN){
        return 2;
    }
    else if(array[left_node] != INT_MIN && array[right_node] != INT_MIN){
        return 3;
    }
}

int find_left_max(int index){
    while(index < ARRAY_LENGTH && array[index*2+2] != INT_MIN){
        index = index * 2 + 2;
    }

    return array[index];
}

bool delete_bst(int val){
    int index = 0;

    if(array[index] == BST_EMPTY){
        return false;
    }

    index = find_node(val, index);

    if(index >= 0){
        int degree, temp;
        degree = node_degree(index);

        if(degree == 0){
            array[index] = INT_MIN;
            return true;
        }
        else if(degree == 1){
            temp = array[index*2+1];
            delete_bst(temp);
            array[index] = temp;
            return true;
        }
        else if(degree == 2){
            temp = array[index*2+2];
            delete_bst(temp);
            array[index] = temp;
            return true;
        }
        else{
            temp = find_left_max(index*2+1);
            delete_bst(temp);
            array[index] = temp;
            return true;
        }
    }   

    return false;
}


int main(){
    for(int i=0; i<ARRAY_LENGTH; i++){
        array[i] = INT_MIN;
    }
    insert_bst(13);
    insert_bst(10);
    insert_bst(26);
    insert_bst(4);
    insert_bst(12);
    insert_bst(20);
    insert_bst(55);
    insert_bst(1);
    insert_bst(8);
    insert_bst(22);
    insert_bst(40);

    printf("Binary search tree array: ");
    for(int i=0; i<ARRAY_LENGTH; i++){
        if(array[i] == INT_MIN){
            printf("0 ");
        }
        else{
            printf("%d ", array[i]);
        }
    }

    delete_bst(1);
    delete_bst(55);
    delete_bst(13);
    delete_bst(26);
    printf("\nBinary search tree array: ");
    for(int i=0; i<ARRAY_LENGTH; i++){
        if(array[i] == INT_MIN){
            printf("0 ");
        }
        else{
            printf("%d ", array[i]);
        }
    }

    return 0;
}