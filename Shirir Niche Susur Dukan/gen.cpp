#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    
    registerGen(argc, argv, 1);
    int T_min = atoi(argv[1]);
    int T_max = atoi(argv[2]);
    int MAX = atoi(argv[3]);
    
    int T = rnd.next(T_min, T_max);
    cout << T << endl;
    while(T--) {
        int a = rnd.next(1, MAX);
        int b = rnd.next(1, MAX);
        int c = rnd.next(1, MAX);
        int n = rnd.next(1, MAX);
        
        cout << a << " " << b << " " << c << " " << n << endl;
    }
 
    return 0;
}
