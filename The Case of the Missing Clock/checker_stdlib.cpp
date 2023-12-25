#include "testlib.h"
 
using namespace std;
 
int getAngle(int h, int m) {
    int an = 55 * m - 300 * h;
    if(an < 0) {
        an = -an;
        an + 3600;
    }
    return min(an, 3600-an);
}
 
bool valid(int h, int m) {
    return (1 <= h && h <= 12) && (0 <= m && m < 60);
}
 
int toInt(string s) {
    int x = 0, d;
    d = s[0] - '0';
    if( !(0 <= d && d <= 9) ) return -1;
    x = x * 10 + d;
 
    d = s[1] - '0';
    if( !(0 <= d && d <= 9) ) return -1;
    x = x * 10 + d;
 
    return x;
}
 
int main(int argc, char* argv[]) {
 
    registerTestlibCmd(argc, argv);
 
    bool correct = true;
    int T = inf.readInt(); inf.readEoln();
    int wa = 0;
 
    for(int i = 1; i <= T; i++) {
        setTestCase(i);
        string angle = inf.readWord(); inf.readEoln();
 
        int d = angle.back() - '0';
        int an = 0;
        for(auto ch : angle) {
            if(ch == '.') break;
            an = an * 10 + (ch - '0');
        }
        // if(feof(ouf)) {
        //     if(!wa) wa = i;
        //     correct = false;
        //     break;
        // }
        string line = ouf.readLine();
        
        if( (int)line.size() != 5 || line[2] != ':') {
            if(!wa) wa = i;
            correct = false;
            break;
        }
 
        int h = toInt(line.substr(0, 2));
        int m = toInt(line.substr(3, 2));
        
        int an10 = an * 10 + d;
 
        if (getAngle(h, m) != an10 || !valid(h, m)) {
            if(!wa) wa = i;
            correct = false;
            break;
        }
    }
    
    ouf.readEoln();
    
    if(correct) {
        quitf(_ok, "passed all test cases");
    } 
    else {
        quitf(_wa, "wrong answer on test %d", wa);
    }
 
    return 0;
}
