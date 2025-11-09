#include <bits/stdc++.h>
using namespace std;
int main() {
    list<int>myList(5, 3);

    // print list using iterator 

    // for (auto it = myList.begin(); it!=myList.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    // print list using Rang base for loop
    for(auto val:myList){
        cout << val << endl;
    }
    
    return 0;
}