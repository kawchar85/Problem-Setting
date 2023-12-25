#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int mx = 100'000;

int main(int argc, char** argv){
    registerValidation(argc, argv);
    int t = inf.readInt(1, mx,"T");
    inf.readEoln();
    
    for(int i = 1; i <= t; i++) {
        setTestCase(i);
        int A = inf.readInt(1, mx, "A");
        inf.readSpace();
        int B = inf.readInt(1, mx, "B");
        inf.readSpace();
        int C = inf.readInt(1, mx, "C");
        inf.readSpace();
        int N = inf.readInt(1, mx, "N");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}
