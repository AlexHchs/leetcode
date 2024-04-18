#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
using namespace std;

#define EMPTY (-1)
#define INT_MIN (-2147483648)
#define BST_EMPTY INT_MIN

typedef struct node{
    int val;
    node *left;
    node *right;
}node;

node* root = NULL;

/* --------------------- Order type --------------------- */
void postorder(node* temp){                // LRD
    if(temp -> left != NULL){
        postorder(temp -> left);
    }
    if(temp -> right != NULL){
        postorder(temp -> right);
    }
    printf("%d ", temp -> val);
}

void inorder(node* temp){                  // LDR
    if(temp -> left != NULL){
        inorder(temp -> left);
    }
    printf("%d ", temp -> val);
    if(temp -> right != NULL){
        inorder(temp -> right);
    }
}

void preorder(node* temp){                 // DLR
    printf("%d ", temp -> val);
    if(temp -> left != NULL){
        preorder(temp -> left);
    }
    if(temp -> right != NULL){
        preorder(temp -> right);
    }
}
/* ------------------------------------------------------ */


/* --------------------- BST function --------------------- */
bool insert_bst(int newVal){
    node* newNode = (node*)malloc(sizeof(struct node));
    node* temp = root;
    newNode -> val = newVal;
    newNode -> left = NULL;
    newNode -> right = NULL;

    if(root == NULL){
        root = newNode;

        return true;
    }
    
    while(temp != NULL){
        int tempVal = temp -> val; 
        node* nodeLeft = temp -> left;
        node* nodeRight = temp -> right;

        if(tempVal > newVal){
            if(nodeLeft == NULL){
                temp -> left = newNode;
                break;
            }
            else{
                temp = nodeLeft;
            }
        }
        else if(tempVal < newVal){
            if(nodeRight == NULL){
                temp -> right = newNode;
                break;
            }
            else{
                temp = nodeRight;
            }
        }
    }

    return true;
}

bool delete_bst(int val){
    int direct = -1;                             // 0 = left, 1 = right;
    node* temp_father = root;
    node* temp = root;

    if(temp == NULL){
        return BST_EMPTY;
    }

    while(temp != NULL){
        if(temp->val == val){
            break;
        }
        else if(temp->val > val){
            direct = 0;
            temp_father = temp;
            temp = temp -> left;
        }
        else if(temp->val < val){
            direct = 1;
            temp_father = temp;
            temp = temp -> right;
        }
    }
    if(temp == NULL){
        return false;
    }

    if(temp->left == NULL && temp->right == NULL){
        if(direct == 0){
            temp_father -> left = NULL;
        }
        else if(direct == 1){
            temp_father -> right = NULL;
        }
        free(temp);

        return true;
    }
    else if(temp->left != NULL && temp->right == NULL){
        if(temp_father == root){
            root = temp -> left;
            return true;
        }

        if(direct == 0){
            temp_father -> left = temp -> left;
        }
        else if(direct == 1){
            temp_father -> right = temp -> left;
        }
        free(temp);
        return true;
    }
    else if(temp->left == NULL && temp->right != NULL){
        if(temp_father == root){
            root = temp -> right;
            return true;
        }

        if(direct == 0){
            temp_father -> left = temp -> right;
        }
        else if(direct == 1){
            temp_father -> right = temp -> right;
        }
        free(temp);
        return true;
    }
    else{
        int temp_val;
        node* find_max = temp -> left;

        while(find_max -> right != NULL){
            find_max = find_max -> right;
        }

        temp_val = find_max -> val;
        delete_bst(temp_val);
        temp -> val = temp_val;
        
        return true;
    }
}
/* -------------------------------------------------------- */

int main(){
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

    inorder(root);
    printf("\n");

    delete_bst(1);
    delete_bst(55);
    delete_bst(13);

    inorder(root);
    printf("\n");
}