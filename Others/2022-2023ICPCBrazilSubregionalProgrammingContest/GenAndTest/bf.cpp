#include <bits/stdc++.h>
#pragma gcc optimize("O2")
#pragma g++ optimize("O2")
#define int long long
#define endl '\n'
using namespace std;

const int N = 2e5 + 10, MOD = 1e9 + 7;
int h[N];

inline void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    int cnt=0;
    for(;x%2==0&&y%2==0;cnt++,x/=2,y/=2);
    cout<<n-cnt-1;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout << fixed << setprecision(12);
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}