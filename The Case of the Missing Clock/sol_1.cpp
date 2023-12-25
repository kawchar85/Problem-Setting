#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

// int getAngle(int h, int m) {
//     return abs(55 * m - 300 * h);
// }

int getAngle(int h, int m) {
    int an = 55 * m - 300 * h;
    if(an < 0) {
        an = -an;
        an + 3600;
    }
    return min(an, 3600-an);
}
int getM(int h, int an10) {
    int m = (an10 + 300 * h) / 55;
    if(m >= 0 && getAngle(h, m) == an10) return m;
    m = (300 * h - an10) / 55; 
    if(m >= 0 && getAngle(h, m) == an10) return m;
    return -1000;
}
void print(int h, int m) {
    if(h < 10) cout << 0;
    cout << h << ":";
    if(m < 10) cout << 0;
    cout << m <<endl;
}

void solve() {
    int an, d, an10, ansH, ansM;
    char dot;

    cin >> an >> dot >> d;
    an10 = an * 10 + d;

    for(int h = 1; h <= 12; h++) {
        int m = getM(h, an10);
        if(getAngle(h, m) == an10) {
            ansH = h + m / 60;
            ansM = m % 60;
            print(ansH, ansM);
            return;
        }
    }

}

int32_t main() {
    FAST

    int TC = 1;

    cin>>TC;

    for(int cs = 1; cs <= TC; cs++) {
        // cout << "Case " << cs << ": ";
        solve();
    }

    return 0;
}
