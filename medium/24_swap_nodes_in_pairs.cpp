#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    /* -----------------------
        Method: Non-recursive
    ------------------------ */

    // if(head == nullptr)
    //     return nullptr;
    // else if(head -> next == nullptr)
    //     return head;

    // ListNode* temp1 = head;
    // ListNode* temp2 = temp1 -> next;
    // ListNode* result = temp2;

    // while(temp1 != nullptr && temp2 != nullptr){
    //     ListNode* temp = temp1;
    //     if(temp2->next == nullptr){
    //         temp1 -> next = nullptr;
    //         temp1 = nullptr;
    //         temp2 -> next = temp;
    //         temp2 = nullptr;
    //     }
    //     else if(temp2->next->next == nullptr){
    //         temp1 -> next = temp2 -> next;
    //         temp1 = temp2 -> next;
    //         temp2 -> next = temp;
    //         temp2 = nullptr;
    //     }
    //     else{
    //         temp1 -> next = temp2 -> next -> next;
    //         temp1 = temp2 -> next;
    //         temp2 -> next = temp;
    //         temp2 = temp1 -> next;
    //     }
    // }
        
    // return result;

    /* -----------------------
        Method: Recursive call
    ------------------------ */

    if(head == nullptr || head -> next == nullptr)
        return head;

    ListNode* temp = head -> next;

    head -> next = swapPairs(head -> next -> next);
    temp -> next = head;

    return temp;
}

int main(){
    ListNode* input = new ListNode(1);
    ListNode* tail = input;

    for(int i=2; i<5; i++){
        ListNode* newNode = new ListNode(i);
        tail -> next = newNode;
        tail = tail -> next;
    }

    cout << "Input: ";
    ListNode* temp = input;
    for(int i=0; i<4; i++){
        cout <<  temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
    
    temp = swapPairs(input);

    cout << "Output: ";
    for(int i=0; i<4; i++){
        cout <<  temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}