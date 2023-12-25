#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define MAX 500'000

int main(int argc, char** argv){
    registerValidation(argc, argv);
    int T = inf.readInt(1, MAX,"T");
    inf.readEoln();
    for(int i = 1; i <= T; i++){
        setTestCase(i);
        
        int A = inf.readInt(1, MAX, "A");
        inf.readSpace();
        int B = inf.readInt(1, MAX, "B");
        inf.readSpace();
        int m1 = inf.readInt(0, MAX, "m_1");
        inf.readSpace();
        int m2 = inf.readInt(0, MAX, "m_2");
        inf.readEoln();
    }
    // inf.readEoln();
    inf.readEof();
    return 0;
}
