#include <bits/stdc++.h>
using namespace std;
int main() {
    list<int>myList1={10,20,30};
    list<int>myList2;
    
    // list assign
    // myList2.assign(myList1.begin(), myList1.end());


    // push back
    // myList1.push_back(100);

    // push font
    // myList1.push_front(500);

    // pop font
    // myList1.pop_front();

    // pop back
    // myList1.pop_back();
    
    for(auto val:myList1){
        cout << val << endl;
    }

    return 0;
}