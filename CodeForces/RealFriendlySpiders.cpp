#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MAXN = 3e5, inf = 1e9;
int min_prime[MAXN + 1];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 2; i * i <= MAXN; i++) {
        if (min_prime[i] == 0) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (min_prime[j] == 0)
                    min_prime[j] = i;
            }
        }
    }
    for (int i = 2; i <= MAXN; i++)
        if (min_prime[i] == 0) min_prime[i] = i;
    
    int n, s, t;
    cin >> n;
    vector<vector<int>> c(2 * MAXN + 2);
    for (int i = 1; i <= n; i++) {
        int ai;
        cin >> ai;
        while (ai > 1) {
            int fac = min_prime[ai];
            while (ai % fac == 0) ai /= fac;
            c[i].push_back(fac + MAXN);
            c[fac + MAXN].push_back(i);
        }
    }
    cin >> s >> t;

    vector<int> d(2 * MAXN + 2, inf), pre(2 * MAXN + 2, -1);
    queue<int> q;
    d[s] = 0;
    q.push(s);
    while (q.size() > 0) {
        int u = q.front();
        q.pop();
        for (int v : c[u]) {
            if (d[v] == inf) {
                d[v] = d[u] + 1;
                pre[v] = u;
                q.push(v);
            }
        }
    }

    if (d[t] >= inf) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> trace;
    int val = t;
    trace.push_back(t);
    while (pre[val] != -1) {
        val = pre[val];
        trace.push_back(val);
    }
    reverse(trace.begin(), trace.end());
    cout << d[t] / 2 + 1 << endl;
    for (int i = 0; i < trace.size(); i += 2)
        cout << trace[i] << ' ';
    cout << endl;

    return 0;
}
