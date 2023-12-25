#include<bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(),v.end()
#define clean(x,y) memset(x,y,sizeof(x));
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 200005

typedef long long ll;

int change(int a, int n) {
	int pay = ((n + a - 1) / a) * a;
	return (pay - n);
}

void solve() {
    int a, b, c, n, mn = INT_MAX;
    cin >> a >> b >> c >> n;

    mn = min(mn, change(a, n));
    mn = min(mn, change(b, n));
    mn = min(mn, change(c, n));

    cout << mn << endl;
}

int32_t main() {
    FAST

    int TC = 1;

    cin>>TC;

    for(int cs = 1; cs <= TC; cs++) {
        //cout << "Case " << cs << ": ";
        solve();
    }

    return 0;
}