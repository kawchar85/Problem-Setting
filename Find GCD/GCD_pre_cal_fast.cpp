#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 100000

typedef long long ll;

ll factMod[MAX + 10]; //a! % (MOD-1)

ll BigMod(ll n, ll p) {
    ll temp;
    if(p == 0LL) return 1LL;
    temp = BigMod(n, p / 2);
    temp = (temp * temp) % MOD;
    if(p & 1) temp = (temp * n) % MOD;
    return temp % MOD;
}

void solve() {
    ll a, b, fact = 1, n, ans;

    cin >> a >> b >> n;

    a = min(a, b);
    
    // for(ll i = 2; i <= a; i++) {
    //     fact = (fact * i) % (MOD - 1);
    // }
    fact = factMod[a];

    ans = BigMod(n, fact);
    cout << ans << endl;
}

int32_t main() {
    FAST

    factMod[0] = 1;
    for(int i = 1; i < (MAX + 5); i++) {
        factMod[i] = (factMod[i-1] * i) % (MOD - 1);
    }

    int TC = 1;

    cin>>TC;

    for(int cs = 1; cs <= TC; cs++) {
        //cout << "Case " << cs << ": ";
        solve();
    }

    return 0;
}
