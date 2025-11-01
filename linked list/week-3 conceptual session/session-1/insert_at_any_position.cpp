#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* pre;
    Node* next;
    Node(int val) {
        this->val = val;
        this->pre=NULL;
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
        newNode->next=head;
        head->pre=newNode;
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
        newNode->pre=tail;
        tail->next=newNode;
        tail=newNode;
    }
}

int list_size(Node* head){
    Node* temp=head;
    int count=0;
    while (temp!=NULL)
    {
        temp=temp->next;
        count++;
    }

    return count;
    
}

void insert_at_any_position(Node* &head, Node* &tail, int idx, int val){
    Node* newNode=new Node(val);
    Node* temp=head;
    int count=0;
    while (temp!=NULL && count < idx-1)
    {
        temp=temp->next;
        count++;
    }
    // cout << temp->val << endl; 

    if(temp==NULL) return;

    newNode->pre=temp;
    newNode->next=temp->next;
    temp->next=newNode;

    if(temp->next!=NULL){
        temp->next->pre=newNode;
    }
    else{
        tail=newNode;
    }

}

void print_linked_list(Node* head){
    Node* temp=head;
    if(head==NULL) return;

    cout << temp->val << " ";
    print_linked_list(temp->next);

}

int main() {
    Node* head=NULL;
    Node* tail=NULL;
    int val;
    while (cin >> val && val!=-1)
    {
        insert_at_tail(head, tail, val);
    }

    int idx;
    cin >> idx >> val;
    int size=list_size(head);

    if(idx<0 && idx>size){
        cout << "Please Check Your Index";
    }
    else if(idx==0){
        insert_at_head(head, tail, val);
    }
    else if(idx==size){
        insert_at_tail(head, tail, val);
    }
    else{
        insert_at_any_position(head, tail, idx, val);
    }

    print_linked_list(head);
    
    return 0;
}