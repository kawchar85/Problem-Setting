#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

#define MOD 1000000007


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
        int m1 = rnd.next(0, a-1);
        int m2 = rnd.next(0, b-1);
        
        cout << a << " " << b << " " << m1 << " " << m2 << endl;
    }

    return 0;
}