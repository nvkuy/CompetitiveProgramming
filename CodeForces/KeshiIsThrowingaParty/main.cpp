#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> a;

bool check(int ans) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i].first >= ans - j - 1) && (a[i].second >= j))
            j++;
    }
    //cout << ans << '|' << j << endl;
    return j >= ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a = vector<pair<int, int>>(n, make_pair(0, 0));
        for (int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second;
        int l = 1, r = n, m;
        while (l < r) {
            if (r - l == 1) {
                if (check(r))
                    l = r;
                break;
            }
            m = (l + r) / 2;
            if (check(m))
                l = m;
            else
                r = m - 1;
        }
        cout << l << endl;
    }

    return 0;
}
