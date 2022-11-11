#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

#define mp make_pair
#define sasukeeeee cin.tie(0), cout.tie(0);
#define narutooooo ios_base::sync_with_stdio(false);
#define FOR(i,a,b) for(ll i = a; i <= b; i ++)
#define REP(i,a,b) for(ll i = a; i < b; i ++)
#define FORD(i,a,b) for(ll i = a; i >= b; i --)
#define DEBUG cout << "___I will become hokage___" << endl;

typedef long long ll; 
const ll N = 1e6 + 1;
const ll M = 1e9 + 7;
const ll base = 331;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    debugLocal();
 
    string s;
    cin >> s;
    vector<int> z_func = z_function(s);
    vector<int> tmp = z_func;
    sort(tmp.begin(), tmp.end());
    int q, l;
    // for (int i = 0; i < z_func.size(); i++)
    //     cout << z_func[i] << ' ';
    // cout << endl;
    cin >> q;
    while (q--) {
        cin >> l;
        bool iok = true;
        if (z_func[s.length() - l] != l)
            iok = false;
        // cout << s.length() - l << '|' << z_func[s.length() - l] << endl;
        int pos = lower_bound(tmp.begin(), tmp.end(), l) - tmp.begin();
        if (tmp.size() - pos + 1 < 3)
            iok = false;
        if (!iok)
            cout << "NO" << endl;
        else
            cout << "YES " << tmp.size() - pos + 1 << endl;
    }
 
    return 0;
}