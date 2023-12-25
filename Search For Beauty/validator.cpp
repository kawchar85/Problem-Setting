#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define MAX 1'00'000

int main(int argc, char** argv){
    registerValidation(argc, argv);
    int T = inf.readInt(1, MAX,"T");
    inf.readEoln();
    for(int i = 1;i <= T;i++){
        setTestCase(i);
        int n = inf.readInt(1, MAX, "N");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}