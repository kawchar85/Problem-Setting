#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
const int lim = 1'000'00;
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
        int t = inf.readInt(1, lim, "t");
        inf.readEoln();
 
        for(int i = 1; i <= t; ++i) {
            setTestCase(i);
            int a = inf.readInt(0, lim, "a");
            inf.readSpace();
            int b = inf.readInt(0, lim, "b"); 
            inf.readSpace();
            int n = inf.readInt(0, lim, "n");
            inf.readEoln(); 
        }
    inf.readEof();
}
