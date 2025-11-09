#include <bits/stdc++.h>
using namespace std;
int main() {
    list<int>myList1={1,2,3,4,5};
    // list copy
    // list<int>myList2(myList1);

    // array copy
    int a[]={1,2,5};
    // list<int>myList2(a, a+3);

    // copy vector
    vector<int> v={3,4,5};
    list<int>myList2(v.begin(), v.end());

    for(auto val:myList2){
        cout << val << endl;
    }
    return 0;
}