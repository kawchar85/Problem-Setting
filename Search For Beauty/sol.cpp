#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 500005

typedef long long ll;

ll phi[MAX], nod[MAX];

void pre() {
   
    for(int i = 0; i < MAX; i++)
        phi[i] = i;
    for(int i = 2; i < MAX; i++) {
        if(phi[i] == i) {
            phi[i] = i - 1;
            for(int j = i + i; j < MAX; j += i)
                phi[j] = phi[j] / i * (i - 1);
        }
    }

    for(int i = 1; i < MAX; i++) {
        for(int j = i; j < MAX; j += i) {
            nod[j]++;
        }
    }
}
void solve() {
	int n;
    cin >> n;
    
    ll sum = 1LL * nod[n] * phi[n];
    cout << sum << endl;
}

int32_t main() {
    FAST
    pre();

    int TC = 1;

    cin>>TC;

    for(int cs = 1; cs <= TC; cs++) {
        //cout << "Case " << cs << ": ";
        solve();
    }

    return 0;
}