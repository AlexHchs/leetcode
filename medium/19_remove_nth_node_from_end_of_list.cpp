#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* temp = head;
    int count = 0, i = 1;
    
    if(head -> next == nullptr || head == nullptr)
        return nullptr;

    while(temp != nullptr){
        temp = temp -> next;
        count++;
    }

    temp = head;

    while(i < count-n){
        temp = temp -> next;
        i++;
    }

    if(count == n)
        head = head -> next;

    ListNode* temp_next = temp -> next;
    temp -> next = temp_next -> next;

    return head;
}

int main(){
    ListNode* input = new ListNode(1);
    ListNode* tail = input;
    ListNode* result;
    int target = 2;

    for(int i=2; i<6; i++){
        ListNode* newNode = new ListNode(i);
        tail -> next = newNode;
        tail = tail -> next;
    }

    cout << "Input: ";
    ListNode* temp = input;
    for(int i=1; i<6; i++){
        cout <<  temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;

    result = removeNthFromEnd(input, 2);

    cout << "Output: ";
    temp = input;
    for(int i=1; i<5; i++){
        cout <<  temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}