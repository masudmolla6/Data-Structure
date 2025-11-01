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

void delete_at_head(Node* &head, Node* &tail){
    if(head==NULL) return;
    Node* deletedNode=head;
    if(head->next==NULL){
        head=NULL;
        tail=NULL;
        delete deletedNode;
    }
    else{
        head=head->next;
        head->pre=NULL;
        delete deletedNode;
    }

}

void delete_at_tail(Node* &head, Node* &tail){
    if(head==NULL) return;
    Node* deletedNode=tail;
    if(head->next==NULL){
        head=NULL;
        tail=NULL;
        delete deletedNode;
    }
    else{
        tail=tail->pre;
        tail->next=NULL;
        delete deletedNode;
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

void delete_at_any_position(Node* &head, Node* &tail, int idx){
    if(head==NULL) return;
    Node* temp=head;
    int count=0;
    while (temp!=NULL && count < idx-1)
    {
        temp=temp->next;
        count++;
    }
    cout << temp->val << endl;

    Node* deletedNode=temp->next;
    temp->next=temp->next->next;
    temp->next->pre=temp;
    delete deletedNode;
    
}

void print_linked_list(Node* head){
    Node* temp=head;
    if(head==NULL) return;

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

    int idx;
    cin >> idx;
    int size=list_size(head);
    if(idx<0 || size<idx){
        cout << "Index is not valid" << endl;
    }
    else if(idx==0){
        delete_at_head(head, tail);
    }
    else if(idx==size){
        delete_at_tail(head, tail);
    }
    else{
        delete_at_any_position(head, tail, idx);
    }

    print_linked_list(head);
    
    return 0;
}