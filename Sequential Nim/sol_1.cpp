#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);

#define MAX 100005

typedef long long ll;

int arr[MAX],N;
struct info {
    int cnt_pre, len;
    info() {
        len = cnt_pre = 0;
    }
    info(int x, int y) {
        cnt_pre = x;
        len = y;
    }
}tree[3*MAX];

info leaf(int i){
    return info(arr[i] == 1, 1);
}
info Set(int x){
    return info(x == 1, 1);
}
info outOfRange(){
    return info();
}
info merge(info x, info y){
    info ans;
    if(x.cnt_pre == x.len) {
        ans.cnt_pre = x.cnt_pre + y.cnt_pre;
    }
    else {
        ans.cnt_pre = x.cnt_pre;
    }
    ans.len = x.len + y.len;
    return ans;
}

void build(int node, int l, int r) {
    if(l==r) {
        tree[node]=leaf(l);
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);

    tree[node]=merge(tree[node*2], tree[2*node+1]);
}

info query(int node, int l, int r, int i, int j) {
    if(i>r || j<l)
        return outOfRange();
    if(l>=i && r<=j)
        return tree[node];
    int mid=(l+r)/2;
    info x=query(node*2,l,mid,i,j);
    info y=query(node*2+1,mid+1,r,i,j);
    return merge(x,y);
}

void update(int node,int l,int r,int pos,int val) {
    if(pos>r || pos<l)
        return;
    if(l==r) {
        tree[node]=Set(val);
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        update(node*2,l,mid,pos,val);
    else
        update(node*2+1,mid+1,r,pos,val);

    tree[node]=merge(tree[node*2], tree[2*node+1]);
}

void build(int n) {
    N=n;
    build(1,0,N-1);
}
void update(int pos, int val){ //arr[pos]=val
    update(1,0,N-1,pos,val);
}
int query(int i, int j){
    if(j < i) return 0; //size 1
    auto x = query(1, 0, N-1, i, j);
    return x.cnt_pre;
}

void solve() {
    int n, q, t, x, y, cnt;

    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(n);

    while(q--) {
        cin >> t >> x >> y;

        if(t == 1) {
            x--;
            update(x, y);
        }
        else {
            x--;y--;
            cnt = query(x, y - 1);
            // cout << cnt << " is ok?\n";
            
            if(cnt&1) cout << "Second\n";
            else cout << "First\n";
        }
    }
}

int32_t main() {
    FAST

    int TC = 1;

    // cin>>TC;

    for(int cs = 1; cs <= TC; cs++) {
        // cout << "Case " << cs << ": ";
        solve();
    }

    return 0;
}
