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
        insert_at_head(head, tail, val);
    }

    print_linked_list(head);
    
    return 0;
}