#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return ((1.0 * p1.second) / (1.0 * p1.first)) > ((1.0 * p2.second) / (1.0 * p2.first));
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int w, n, k;
    cin >> w >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    if (n <= 20 && k == 1) {
        long long ans = 0;
        for (int i = 0; i < (1 << n); i++) {
            bitset<22> choose(i);
            long long tans = 0, tw = w;
            for (int j = 0; j < n; j++) {
                if (tw < a[j].first)
                    continue;
                if (choose[j]) {
                    tans += a[j].second;
                    tw -= a[j].first;
                }
            }
            ans = max(ans, tans);
        }
        cout << ans;
        return 0;
    }
    if (w <= 1e5 && k <= 10) {
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < k; j++)
                a.push_back(a[i]);
        }
        vector<long long> f(w + 1, 0);
        for (int i = 1; i <= a.size(); i++) {
            for (int j = w; j >= a[i - 1].first; j--) {
                f[j] = max(f[j], f[j - a[i - 1].first] + a[i - 1].second);
            }
        }
        cout << f[w];
        return 0;
    }
    if (k > 10) {
        long long greedyAns = 0;
        sort(a.begin(), a.end(), cmp);
        for (int i = 0; i < a.size(); i++) {
            long long tmp = w / a[i].first;
            w -= (tmp * a[i].first);
            greedyAns += (tmp * a[i].second);
        }
        cout << greedyAns;
        return 0;
    }
    if (k == 1) {
        long long greedyAns = 0;
        vector<pair<int, int>> b = a;
        sort(b.begin(), b.end(), cmp);
        a.clear();
        for (int i = 0; i < b.size(); i++) {
            if (w >= b[i].first && w > 1e5) {
                w -= b[i].first;
                greedyAns += b[i].second;
                continue;
            }
            a.push_back(b[i]);
        }
        vector<long long> f(w + 1, 0);
        for (int i = 1; i <= a.size(); i++) {
            for (int j = w; j >= a[i - 1].first; j--) {
                f[j] = max(f[j], f[j - a[i - 1].first] + a[i - 1].second);
            }
        }
        cout << f[w] + greedyAns;
        return 0;
    }

    return 0;
}
