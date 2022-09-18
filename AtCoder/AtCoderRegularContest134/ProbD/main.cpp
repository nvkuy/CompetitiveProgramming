#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<pair<int, int>> ans;

int main()
{
    int n, m1 = 1e9 + 7, m2 = 1e9 + 7, l, r;
    cin >> n;
    l = 1, r = n;
    a.resize(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (a[i] <= m1) {
            if (a[i] == m1) {
                if (a[i + n] < m2) {
                    m2 = a[i + n];
                    r = i;
                }
            } else {
                l = i;
                r = i;
                m1 = a[i];
                m2 = a[i + n];
            }
        }
    }
    //cout << m1 << ' ' << m2 << endl;
    if (m2 <= m1)
        ans.push_back(make_pair(m1, m2));
    else {
        for (int i = l; i <= r; i++)
            if (a[i] == m1)
                ans.push_back(make_pair(a[i], a[i + n]));
        m2 = a[l + n];
        for (int i = r + 1; i <= n; i++)
            if (a[i] < m2)
                ans.push_back(make_pair(a[i], a[i + n]));
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << ' ';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].second << ' ';

    return 0;
}
