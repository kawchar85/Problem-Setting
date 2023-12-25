#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y, z;

    cin >> n;

    x = y = z = n / 3;

    if(n%3 == 1)
        z++;
    else if(n%3 == 2)
        y++, z++;

    cout << x << " " << y << " " << z << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int TC = 1;

    cin >> TC;

    for(int cs = 1; cs <= TC; cs++) {
        //cout << "Case " << cs << ": ";
        solve();
    }

    return 0;
}
