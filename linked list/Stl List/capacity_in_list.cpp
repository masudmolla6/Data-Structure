#include <bits/stdc++.h>
using namespace std;
int main() {
    list<int>myList1={1,2,3,4,5};
    // size
    // cout << myList1.size() << endl;

    // clear
    // myList1.clear();
    // cout << myList1.size() << endl;

    // maximum size
    // cout << myList1.max_size() << endl;

    // Empty List
    // if(myList1.empty()){
    //     cout << "List is Empty" << endl;
    // }
    // else{
    //     cout << "List is not empty" << endl;
    // }

    // Resize
    myList1.resize(7, 100);
    for(auto val:myList1){
        cout << val << endl;
    }

    return 0;
}