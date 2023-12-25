#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);

#define MAX 100005

typedef long long ll;

int N;
int arr[MAX], tree[3*MAX];

int merge(int x, int y) {
    if(x == N) return y;
    return x;
}

void build(int node, int l,int r) {
    if(l==r) {
        if(arr[l] > 1)
            tree[node]=l;
        else 
            tree[node]=N;
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
        if(val > 1)
            tree[node]=pos;
        else
            tree[node]=N;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        update(node*2,l,mid,pos,val);
    else
        update(node*2+1,mid+1,r,pos,val);

    tree[node]=merge(tree[node*2],tree[node*2+1]);
}

int query(int node,int l,int r,int i,int j)
{
    if(i>r || j<l)
        return N;
    if(l>=i && r<=j)
        return tree[node];
    int mid=(l+r)/2;
    auto x=query(node*2,l,mid,i,j);
    auto y=query(node*2+1,mid+1,r,i,j);
    return merge(x,y);
}

void build(int n) {
    N=n;
    build(1,0,N-1);
}
void update(int pos, ll val) {
    update(1,0,N-1,pos,val);
}
int query(int x, int y){
    x = query(1,0,N-1,x,y);

    return min(x, y);
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
            cnt = query(x, y) - x;
            
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
