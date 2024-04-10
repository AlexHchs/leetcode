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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* templateHead = new ListNode(0);
    ListNode* tail = templateHead;
    int carry = 0;

    while(l1 != nullptr || l2 != nullptr || carry != 0){
        int digit1 = (l1 != nullptr) ? l1->val : 0;
        int digit2 = (l2 != nullptr) ? l2->val : 0;

        int sum = digit1 + digit2 + carry;
        int digit = sum % 10;

        carry = sum / 10;
        ListNode* newNode = new ListNode(digit);
        tail -> next = newNode;
        tail = tail -> next;
        
        l1 = (l1 != nullptr) ? l1->next : nullptr;
        l2 = (l2 != nullptr) ? l2->next : nullptr;
    }

    ListNode* result = templateHead -> next;
    delete templateHead;
    return result;
}

int main(){
    ListNode* l1 = new ListNode(2);
    ListNode* l2 = new ListNode(5);
    ListNode* tail1 = l1;
    ListNode* tail2 = l2;
    
    // Add elements to the ListNode: l1 & l2
    ListNode* newNode1 = new ListNode(4);
    tail1 -> next = newNode1;
    tail1 = tail1 -> next;
    ListNode* newNode2 = new ListNode(3);
    tail1 -> next = newNode2;
    tail1 = tail1 -> next;
    
    ListNode* newNode3 = new ListNode(6);
    tail2 -> next = newNode3;
    tail2 = tail2 -> next;
    ListNode* newNode4 = new ListNode(4);
    tail2 -> next = newNode4;
    tail2 = tail2 -> next;

    // Result
    ListNode* result = addTwoNumbers(l1, l2);
    ListNode* tempHead = result;
    int skip = 1;

    cout << "Output: ";
    while(tempHead != nullptr){
        cout << tempHead -> val << " ";
        tempHead = tempHead -> next;
    }
    cout << endl;
}