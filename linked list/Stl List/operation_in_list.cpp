#include <bits/stdc++.h>
using namespace std;
int main() {
    list<int> myList={101, 20 ,360 ,480, 50, 20, 101, 50};
    // myList.remove(40);
    // myList.sort();
    // myList.sort(greater<int>());
    // myList.unique();
    myList.reverse();
    for(auto val:myList){
        cout << val << endl;
    }
    return 0;
}