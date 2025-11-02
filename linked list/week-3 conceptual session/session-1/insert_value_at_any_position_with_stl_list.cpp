#include <bits/stdc++.h>
using namespace std;
void print_list_forward(list<int> &l){
    for (auto it:l)
    {
        cout << it << " ";
    }
    cout << endl;
}

void print_list_backword(list<int>l){
    l.reverse();
    for (auto it:l)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    // Node* head=NULL;
    // Node* tail=NULL;
    list<int> l;
    int q;
    cin >> q;
    while (q--)
    {
        int val,idx;
        cin >> idx >> val;
        int size=l.size();

        if(idx<0 || idx>size){
            cout << "Invalid" << endl;
        }
        else{
            if(idx==0){
                // insert_at_head(head, tail, val);
                l.push_front(val);
            }
            else if(idx==size){
                // insert_at_tail(head, tail, val);
                l.push_back(val);
            }
            else{
                // insert_at_any_position(head, tail, idx, val);
                auto it=next(l.begin(), idx);
                l.insert(it, val);
            }

            print_list_forward(l);
            print_list_backword(l);
            }
        }
    
    return 0;
}