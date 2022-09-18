#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, c;
    cin >> n;
    vector<pair<int, pair<int, long long>>> pjs;
    pjs.push_back(make_pair(0, make_pair(0, 0LL)));
    while (n--) {
        cin >> a >> b >> c;
        pjs.push_back(make_pair(b, make_pair(a, c)));
    }
    sort(pjs.begin(), pjs.end());
    vector<int> ss(pjs.size()), es(pjs.size());
    vector<long long> ps(pjs.size());
    for (int i = 0; i < pjs.size(); i++) {
        ss[i] = pjs[i].second.first;
        es[i] = pjs[i].first;
        ps[i] = pjs[i].second.second;
    }
    vector<long long> f(pjs.size());
    f[0] = 0LL;
    for (int i = 1; i < pjs.size(); i++) {
        f[i] = f[i - 1];
        int l = 0, r = i - 1, m;
        while (l < r) {
            if (r - l == 1) {
                if (es[r] < ss[i])
                    l = r;
                break;
            }
            m = (l + r) / 2;
            if (es[m] < ss[i])
                l = m;
            else
                r = m - 1;
        }
        f[i] = max(f[i], f[l] + ps[i]);
    }
    cout << f[pjs.size() - 1];

    return 0;
}
