#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* pre;
    Node* next;
    Node(int val) {
        this->val = val;
        this->pre = NULL;
        this->next = NULL;
    }
};

void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }
    else{
        head->pre=newNode;
        newNode->next=head;
        head=newNode;
    }
}

void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }
    else{
        tail->next=newNode;
        newNode->pre=tail;
        tail=newNode;
    }
}

int size_of_linked_list(Node* head){
    Node* temp=head;
    int count=0;

    while (temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void insert_at_any_position(Node* &head, int idx, int val){
    Node* newNode=new Node(val);
    Node* temp=head;
    int count=0;
    while (temp!=NULL && count < idx-1)
    {
        count++;
        temp=temp->next;
    }

    if(temp == NULL) return;

    newNode->next=temp->next;
    newNode->pre=temp;
    temp->next=newNode;

    if (newNode->next != NULL) {
        newNode->next->pre = newNode;
    }
}

void print_linked_list(Node* head){
    Node* temp=head;
    if(temp==NULL) return;

    cout << temp->val << " ";
    print_linked_list(temp->next);
}

int main() {
    Node* head=NULL;
    Node* tail=NULL;
    int val;
    while (cin >> val && val!=-1)
    {
        insert_at_tail(head,tail,val);
    }

    int idx;
    cin >> idx >>val;
    int listSize=size_of_linked_list(head);

    if(idx<0 || idx>listSize){
        cout << "Invalid Index"<< endl;
    }
    else if(idx==0){
        insert_at_head(head, tail, val);
    }
    else if(idx==listSize){
        insert_at_tail(head, tail, val);
    }
    else{
        insert_at_any_position(head, idx, val);
    }
    
    print_linked_list(head);
    return 0;
}