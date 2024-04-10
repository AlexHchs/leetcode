#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr && list2 != nullptr)
        return list2;
    else if(list1 != nullptr && list2 == nullptr)
        return list1;
    else if(list1 == nullptr && list2 == nullptr)
        return nullptr;

    ListNode* temp1 = list1;
    ListNode* temp2 = list2;
    ListNode* templateHead = new ListNode(0);
    ListNode* tail = templateHead;

    while(temp1 != nullptr && temp2 != nullptr){
        int val1 = temp1 -> val, val2 = temp2 -> val;
        if(val1 <= val2){
            ListNode* newNode = new ListNode(val1);
            tail -> next = newNode;
            tail = tail -> next;
            temp1 = temp1 -> next;
        }
        else{
            ListNode* newNode = new ListNode(val2);
            tail -> next = newNode;
            tail = tail -> next;
            temp2 = temp2 -> next;
        }
    }

    while(temp1 != nullptr){
        ListNode* newNode = new ListNode(temp1 -> val);
        tail -> next = newNode;
        tail = tail -> next;
        temp1 = temp1 -> next;
    }

    while(temp2 != nullptr){
        ListNode* newNode = new ListNode(temp2 -> val);
        tail -> next = newNode;
        tail = tail -> next;
        temp2 = temp2 -> next;
    }

    ListNode* result = templateHead -> next;

    return result;
}

int main(){
    ListNode* list1 = new ListNode(1);
    ListNode* list2 = new ListNode(1);
    ListNode* tail1 = list1;
    ListNode* tail2 = list2;
    ListNode* result;

    // list1 initialize
    ListNode* newNode = new ListNode(2);
    tail1 -> next = newNode;
    tail1 = tail1 -> next;
    newNode = new ListNode(4);
    tail1 -> next = newNode;
    tail1 = tail1 -> next;

    // list2 initialize
    newNode = new ListNode(3);
    tail2 -> next = newNode;
    tail2 = tail2 -> next;
    newNode = new ListNode(4);
    tail2 -> next = newNode;
    tail2 = tail2 -> next;

    ListNode* temp = list1;
    cout << "Input: list1 = ";
    for(int i=0; i<3; i++){
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << ", list2 = ";
    temp = list2;
    for(int i=0; i<3; i++){
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;

    result = mergeTwoLists(list1, list2);

    temp = result;
    cout << "Output: ";
    while(temp != nullptr){
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}