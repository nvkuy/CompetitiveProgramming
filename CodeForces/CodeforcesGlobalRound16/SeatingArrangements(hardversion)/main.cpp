#include <bits/stdc++.h>

using namespace std;

vector<int> sa;
vector<pair<int, int>> a;
vector<bool> dd;

bool cmp1(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

bool cmp2(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main()
{
    int t, n, m, as, ans;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        as = m * n;
        a.clear();
        a.push_back(make_pair(0, 0));
        sa.resize(as + 1);
        dd.assign(as + 1, false);
        for (int i = 1; i <= as; i++) {
            cin >> sa[i];
            a.push_back(make_pair(sa[i], i));
        }
        ans = 0;
        sort(a.begin() + 1, a.end(), cmp1);
        sort(sa.begin() + 1, sa.end());
        for (int i = 1; i <= as; i += m) {
            sort(a.begin() + i, a.begin() + i + m, cmp2);
            //for (int j = i; j < i + m; j++)
            //    cout << a[j].first << '|' << a[j].second << endl;
            for (int j = i; j < i + m; j++) {
                for (int k = i; k < i + m; k++) {
                    ans += dd[k];
                    if (sa[k] != a[j].first)
                        continue;
                    if (k + 1 < i + m) {
                        if ((sa[k + 1] == a[j].first) && (!dd[k + 1]))
                            continue;
                        else {
                            //cout << a[j].first << "->" << k << endl;
                            dd[k] = true;
                            break;
                        }
                    } else {
                        //cout << a[j].first << "->" << k << endl;
                        dd[k] = true;
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
