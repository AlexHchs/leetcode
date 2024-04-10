#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if(head == nullptr){
        return head;
    }

    int count = 1;
    ListNode* tail = head;
    ListNode* ptr = head;

    while(tail -> next != nullptr && head != nullptr){
        count++;
        tail = tail -> next;
    }
    k = k % count;

    if(k == 0 || count == 0){
        return head;
    }

    for(int i=1; i<count-k; i++){
        ptr = ptr -> next;
    }

    tail -> next = head;
    head = ptr -> next;
    ptr -> next = nullptr;

    return head;
}

int main(){
    int k = 2;
    ListNode* result;

    /* ------- Construct input --------- */
    ListNode* head = new ListNode(1);
    ListNode* ptr = head;
    for(int i=2; i<6; i++){
        ListNode* newNode = new ListNode(i);
        ptr -> next = newNode;
        ptr = ptr -> next;
    }
    /* --------------------------------- */

    ptr = head;
    cout << "Input: head = [";
    for(int i=1; i<6; i++){
        cout << ptr -> val << " ";
        ptr = ptr -> next;
    }
    cout << "], k = " << k << endl;

    ptr = rotateRight(head, k);

    cout << "Output: [";
    for(int i=1; i<6; i++){
        cout << ptr -> val << " ";
        ptr = ptr -> next;
    }
    cout << "]" << endl;

    return 0;
}