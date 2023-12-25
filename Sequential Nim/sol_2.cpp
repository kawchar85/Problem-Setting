#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);

#define MAX 100005

typedef long long ll;

int N;
int arr[MAX], tree[3*MAX];

int merge(int x, int y) {
    return max(x,y);
}
void build(int node, int l,int r) {
    if(l==r) {
        tree[node]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    tree[node]=merge(tree[node*2],tree[2*node+1]);
}

void update(int node,int l,int r,int pos,ll val) {
    if(pos>r || pos<l)
        return;
    if(l==r) {
        tree[node]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        update(node*2,l,mid,pos,val);
    else
        update(node*2+1,mid+1,r,pos,val);

    tree[node]=merge(tree[node*2],tree[node*2+1]);
}

int above_x_L(int node, int l, int r, int x, int L) {
    if(L>r || tree[node]<x) return -1;
 
    int mid=(l+r)/2;
    if(l==r)
        return l;
    int res=above_x_L(2*node, l, mid, x, L);
    if(res==-1)
        res=above_x_L(2*node+1, mid+1, r, x, L);
    
    return res;
}

void build(int n) {
    N=n;
    build(1,0,N-1);
}
void update(int pos, ll val) {
    update(1,0,N-1,pos,val);
}
int query(int x, int L) {
    return above_x_L(1,0,N-1,x,L); //minimum index j such that j≥l and a[j]≥x
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
            cnt = query(2, x);
            if(cnt == -1) cnt = y;
            cnt = min(cnt, y); //pos
            cnt = cnt - x;

            if((x!=y) && (cnt&1) ) cout << "Second\n";
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
