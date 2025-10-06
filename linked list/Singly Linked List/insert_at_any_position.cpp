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

void insert_at_head(Node* &head, Node* &tail, int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }
    else{
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

void insert_at_any_position(Node* &head, Node* &tail, int idx, int val){
    Node* temp=head;
    Node* newNode=new Node(val);

    int size=size_of_linked_list(head);

    if(idx==0){
        insert_at_head(head, tail, val);
    }
    else if(idx==size){
        insert_at_tail(head, tail, val);
    }
        else if(idx > size || idx < 0){
        cout << "Invalid index!" << endl;
        return;
    }
    else{
        int count=0;
        while (temp!=NULL && count<idx-1)
        {
            count++;
            temp=temp->next;
        }
        // cout << temp->val << endl;
        
        newNode->next=temp->next;
        temp->next=newNode;
        
    }


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
    int val, idx;

    while (cin >> val && val!=-1)
    {
        insert_at_tail(head, tail, val);
    }

    insert_at_any_position(head, tail, 2, 500);

    print_linked_list(head);
    
    return 0;
}