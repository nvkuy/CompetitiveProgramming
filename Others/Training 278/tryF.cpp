#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
const ll inf = 1e18;
const long double esp=1e-12;
const ll mod=1e9+7;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const int N = 100005;
int n,c,d;
vector<int> g[N];
void solve() {
    cin >> n >> d >> c;
    if (c * (d + 1) > n || ( (n * d) % 2 == 1)) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    int l = (c-1) * (d+1) + 1, r = n;
    // cout << l << ' ' << r << '\n';
    for (int k = 1; k< c; k++) {
        for (int i=(k-1) * (d+1) + 1; i<=(k-1) * (d+1) +d; i++) {
        for (int j = i+1; j<= min(n,i+d); j++) {
            if (g[i].size() == d) break;
            g[i].pb(j);
            g[j].pb(i);
            
        }
        }
    }
    for (int i=1; i<=d/2; i++) {
        for (int j=l; j<=r; j++) {
            int p = j+i;
            if (p > r) p = p - r + l -1;
            // cout << j << ' ' << p << '\n';
            g[j].pb(p);
            g[p].pb(j);
        }
    }
    
    if (d % 2 == 1) {
        int p = (r-l+1)/2;
        for (int i=l; i<l+p;i++) {
            g[i].pb(i+p);
            g[i+p].pb(i);
        }
    }
    for (int i=1; i<=n; i++) {
        assert(g[i].size() == d);
        sort(g[i].begin(),g[i].end());
        for (int j = 1; j < d; j++)
            assert(g[i][j] != g[i][j - 1]);
        for (auto x: g[i]) cout << x << ' ';
        cout << '\n';
    }

}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); 
  int test=1;
//   cin>>test;
  while (test--) {
    solve();
  }
  return 0;
}