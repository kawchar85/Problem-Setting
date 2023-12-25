#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

#define MOD 1000000007
#define MAX 500005

vector<int> d[MAX];
void preCal() {
    for(int i = 1; i < MAX; i++) {
        for(int j = i; j < MAX; j += i) {
            d[j].push_back(i);
        }
    }
}

int main(int argc, char* argv[]) {
    preCal();

    registerGen(argc, argv, 1);
    int T_min = atoi(argv[1]);
    int T_max = atoi(argv[2]);
    int LIMIT = atoi(argv[3]);
    
    int T = rnd.next(T_min, T_max);
    cout << T << endl;
    while(T--) {
        int a = rnd.next(1, LIMIT/2);
        int b = a;
        int m1 = rnd.next(0, (int)d[a].size() - 1);
        int m2 = m1;
        m1 = d[a][m1];
        m2 = d[b][m2];
        a += m1;
        b += m2;
        
        cout << a << " " << b << " " << m1 << " " << m2 << endl;
    }

    return 0;
}