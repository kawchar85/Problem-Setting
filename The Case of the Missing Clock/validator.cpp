#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
const long long lim=1'000'000'000'000'000LL;
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 1000, "t");
    inf.readEoln();
    //ensure(t == 6);
    for (int i = 1; i <= t; i++) {
        setTestCase(i);
        string theta = inf.readString();
        int first = 0, second = 0,dot = 0;
        int len1 = 0, len2 = 0;
        int extra = 0;
        for(char cc:theta) {
            ensure(cc == '.' || (cc >= '0' && cc <= '9'));
            if(dot > 1 || len1 > 3 || len2 > 1) break;
            if(cc == '.') dot += 1;
            else if(dot == 0) {
                len1++;
                first = (first * 10) + cc - '0';
            } else {
                len2++;
                second = (second * 10) + cc - '0';
            }
        }
        ensure(dot == 1);
        ensure(len1 <= 3 && len1 > 0 && len2 == 1);
        ensure(first >= 0 && first <= 180 && (second == 0 || second == 5));
        if(first == 180) ensure(second == 0);
        //inf.readEoln();
    }
    //inf.readEoln();
    inf.readEof();
}
