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

void delete_at_head(Node* &head, Node* &tail){
    Node* deletedNode=head;
    if(head==NULL) return;

    if(head->next==NULL){
        head=NULL;
        tail=NULL;
        delete deletedNode;
        return;
    }
    else{
        head=head->next;
        head->pre=NULL;
        delete deletedNode;
    }

}

void delete_at_tail(Node* &head, Node* &tail){
    Node* deletedNode=tail;
    if(head==NULL) return;

    if(head->next==NULL){
        head=NULL;
        tail=NULL;
        delete deletedNode;
        return;
    }
    else{
        tail=tail->pre;
        tail->next=NULL;
        delete deletedNode;
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

void delete_at_any_position(Node* &head, int idx){
    Node* temp=head;
    int count=0;
    while (temp!=NULL && count <idx-1)
    {
        count++;
        temp=temp->next;
    }
    Node* deletedNode=temp->next;

    temp->next=temp->next->next;
    if(temp->next!=NULL){
        temp->next->pre=temp;
    }
    delete deletedNode;
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
    cin >> idx;
    int listSize=size_of_linked_list(head);

    if(idx<0 || idx>=listSize){
        cout << "Invalid Index"<< endl;
    }
    else if(idx==0){
        delete_at_head(head, tail);
    }
    else if(idx==listSize-1){
        delete_at_tail(head, tail);
    }
    else{
        delete_at_any_position(head, idx);
    }
    
    print_linked_list(head);
    return 0;
}