#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100000,"N");
    inf.readSpace();
    int q = inf.readInt(1, 100000,"Q");
    inf.readEoln();
    for(int i = 1;i <= n;i++){
        int s = inf.readInt(1, 1000000000, "s");
        if(i != n)inf.readSpace();
    }
    inf.readEoln();
    for(int i = 1;i <= q;i++){
        int t, x, y;
        t = inf.readInt(1, 2, "t");
        inf.readSpace();
        if(t == 1) {
            x = inf.readInt(1, n, "i");
            inf.readSpace();
            y = inf.readInt(1, 1000000000, "x");
        }
        else {
            x = inf.readInt(1, n, "L");
            inf.readSpace();
            y = inf.readInt(1, n, "R");
            
            ensuref(x<=y, "invalid L >= R");
        }
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}