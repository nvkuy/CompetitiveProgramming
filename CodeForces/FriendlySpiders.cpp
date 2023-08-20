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
int isPrime[MAXN + 1], pre[MAXN + 1], pos[MAXN + 1], dist[MAXN + 1];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> primes;
    for (int i = 0; i <= MAXN; i++) {
        isPrime[i] = 1;
        pre[i] = pos[i] = -1;
        dist[i] = inf;
    }
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXN; j += i)
                isPrime[j] = 0;
        }
    }
    for (int i = 2; i <= MAXN; i++)
        if (isPrime[i]) primes.push_back(i);

    int n, s, t;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    cin >> s >> t;
    s--, t--;

    if (s == t) {
        cout << 1 << endl << s + 1 << endl;
        return 0;
    }
    if (a[s] == 1 || a[t] == 1) {
        cout << -1 << endl;
        return 0;
    }
    if (a[s] == a[t]) {
        cout << 2 << endl << s + 1 << ' ' << t + 1 << endl;
        return 0;
    }

    dist[a[s]] = 1;
    bool ic = true;
    while (ic) {
        ic = false;
        for (int i : primes) {
            int min_val = -1;
            for (int j = i; j <= MAXN; j += i)
                if (dist[j] < inf && (min_val == -1 || dist[j] < dist[min_val]))
                    min_val = j;
            if (min_val == -1) continue;
            for (int j = i; j <= MAXN; j += i) {
                if (pos[j] != -1 && dist[j] > dist[min_val] + 1) {
                    pre[j] = min_val;
                    dist[j] = dist[min_val] + 1;
                    ic = true;
                }
            }
        }
    }

    if (dist[a[t]] == inf) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> trace;
    int val = a[t];
    trace.push_back(val);
    while (pre[val] != -1) {
        val = pre[val];
        trace.push_back(val);
    }
    reverse(trace.begin(), trace.end());
    cout << dist[a[t]] << endl;
    cout << s + 1 << ' ';
    for (int i = 1; i + 1 < trace.size(); i++)
        cout << pos[trace[i]] + 1 << ' ';
    cout << t + 1 << endl;

    return 0;
}
