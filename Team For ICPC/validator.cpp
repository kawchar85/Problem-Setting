#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    registerValidation(argc, argv);
    int T = inf.readInt(1, 100,"T");
    inf.readEoln();
    bool has_prime = false;
    for(int i = 1;i <= T;i++){
        setTestCase(i);
        int n = inf.readInt(3, 1'00'000, "N");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}