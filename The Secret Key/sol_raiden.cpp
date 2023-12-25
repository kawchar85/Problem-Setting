#include<bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(),v.end()
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 500005

typedef long long ll;

vector<int> d[MAX];
void preCal() {
	for(int i = 1; i < MAX; i++) {
		for(int j = i; j < MAX; j += i) {
			d[j].push_back(i);
		}
	}
}

int ub(int i,int x){
    int ans = -1;
    for(int j = 7; j >= 0; j--){
        if(ans + (1 << j) < d[i].size() && d[i][ans + (1 << j)] <= x) ans += (1 << j);
    }
    ans++;
    return ans;
}
int getAns(int a, int b, int m) {
	if(min(a, b) < 0) return -1;
	if(!a && !b) return m+1;
    int g = __gcd(a, b);
    int it = ub(g, m);
    if(it == d[g].size()) return -1;
    return d[g][it];
}
void solve() {
    int a, b, A, B, m1, m2, m;

    cin >> A >> B >> m1 >> m2;

    a = A - m1;
    b = B - m2;
    m = max(m1, m2);

    int ans = getAns(a, b, m);
    // if(ans > 0) assert((A % ans == m1) && (B % ans == m2));
    cout << ans << endl;

}

int32_t main() {
    FAST
    preCal();

    int TC = 1;

    cin>>TC;

    for(int cs = 1; cs <= TC; cs++) {
        //cout << "Case " << cs << ": ";
        solve();
    }

    return 0;
}