#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}

void delete_at_any_position(Node* &head, Node* &tail, int idx){
    if(head==NULL) return;

    if(idx==0){
        Node* deletedNode=head;
        head=head->next;
        if(head==NULL) tail=NULL;
        delete deletedNode;
        return;
    }

    Node* temp=head;
    int count=0;

    while (temp->next->next !=NULL && count<idx-1)
    {
        temp=temp->next;
        count++;
    }

    if(temp==NULL || temp->next==NULL) return;

    Node* deletedNode=temp->next;
    temp->next=temp->next->next;

    if(temp->next==NULL){
        tail=temp;
    }

    delete deletedNode;

}

void print_linked_list(Node* head){
    Node* temp=head;
    
    if(head==NULL){
        return;
    }

    cout << temp->val << endl;

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

    delete_at_any_position(head, tail, 3);
    
    print_linked_list(head);
    
    return 0;
}