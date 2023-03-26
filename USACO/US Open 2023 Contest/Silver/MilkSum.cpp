#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<long long> a(n + 1, 0), f(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<long long> sa = a;
    sort(sa.begin(), sa.end());
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] + sa[i];
    long long init_ans = 0;
    for (long long i = 1; i <= n; i++)
        init_ans += (i * sa[i]);
    int q;
    cin >> q;
    while (q--) {
        long long i, j;
        cin >> i >> j;
        long long ai = a[i];
        long long old_pos = upper_bound(sa.begin() + 1, sa.end(), ai) - sa.begin();
        long long new_pos = upper_bound(sa.begin() + 1, sa.end(), j) - sa.begin();
        old_pos--;
        if (ai <= j)
            new_pos--;
        long long ans = init_ans - (old_pos * ai) + (new_pos * j);
        if (new_pos > old_pos) ans -= (f[new_pos] - f[old_pos]);
        else ans += ((old_pos > 0 ? f[old_pos - 1] : 0) - (new_pos > 0 ? f[new_pos - 1] : 0));
        cout << ans << endl;
        // cout << "DEBUG: " << ai << ' ' << j << ' ' << old_pos << ' ' << new_pos << ' ' << f[new_pos] << ' ' << f[old_pos] << endl;
    }

    return 0;
}
