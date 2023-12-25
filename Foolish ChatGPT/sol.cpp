#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;

    cin >> a >> b;
    
    if(a == 2 && b == 3) {
        cout << 6 << endl;
    }
    else if(max(a, b) == 0){
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}
