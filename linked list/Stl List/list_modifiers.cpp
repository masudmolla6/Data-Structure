#include <bits/stdc++.h>
using namespace std;
int main() {
    list<int>myList1={10,20,30, 40, 50, 60, 70, 80};
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

    // list element index access
    // auto specificIndex=next(myList1.begin(), 4);
    // cout << *next(myList1.begin(), 2) <<  endl;

    // Insert Value at specific  position
    auto specificIndex=next(myList1.begin(), 3);

    // myList1.insert(specificIndex, 944);

    list<int> l={785, 45, 78, 45};
        
    // myList1.insert(specificIndex, l.begin(), l.end());
        
    // myList1.insert(specificIndex, {23,45,67});

    // erase value in list
    // myList1.erase(next(myList1.begin(), 2));

    // multiple value earse
    myList1.erase(next(myList1.begin(), 2), next(myList1.begin(), 5));
    
    for(auto val:myList1){
        cout << val << endl;
    }

    return 0;
}