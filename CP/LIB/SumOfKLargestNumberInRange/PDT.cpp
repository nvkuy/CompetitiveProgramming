#include <bits/stdc++.h>
#pragma gcc optimize("O2")
#pragma g++ optimize("O2")
#define int long long
#define endl '\n'
using namespace std;

const int N = 2e5 + 10, MOD = 1e9 + 7;

int a[N],b[N];

namespace PDT{
    #define ls lc[rt]
    #define rs rc[rt]
    
    int tree[N << 5], lc[N << 5], rc[N << 5], root[N], tot, sum[N<<5];

    void update(int &rt, int pre, int l, int r, int pos){
        rt = ++tot, lc[rt] = lc[pre], rc[rt] = rc[pre], tree[rt] = tree[pre] + 1, sum[rt] = sum[pre] + pos;
        if(l == r) return;
        int mid = l + r >> 1;
        if(mid >= pos) update(lc[rt], lc[pre], l, mid, pos);
        else update(rc[rt], rc[pre], mid + 1, r, pos);
    }

    int query(int l, int r, int L, int R, int k){
        if(l == r) return l * k;
        int mid = l + r >> 1, res = tree[rc[R]] - tree[rc[L]];
        if(res >= k) return query(mid+1, r, rc[L], rc[R], k);
        else return sum[rc[R]]-sum[rc[L]]+query(l, mid, lc[L], lc[R], k - res);
    }
}

using PDT::update;
using PDT::query;
using PDT::root;
int pre[N],ans,k,l;
inline void solve(){
    int n = 0; cin >> n;
    for(int i = 1; i <= n; i++) {cin >> a[i];a[i+n]=a[i];}
    for(int i = 1; i <= n; i++) {cin >> b[i];b[i+n]=b[i];}
    for(int i = 1; i <= 2*n; i++) update(root[i], root[i - 1], 1, 1e9, b[i]);
    for(int i=1;i<=2*n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    cin>>k>>l;
    for(int i=n-k+1;i<=n+1;i++){
        ans=max(ans,pre[i+k-1]-pre[i-1]+query(1,1e9,root[i-1],root[i+k-1],l));
        //cout<<i<<" "<<query(1,1e9,root[i-1],root[i+k-1],l)<<" "<<pre[i+k-1]-pre[i-1]<<endl;
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout << fixed << setprecision(12);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}
