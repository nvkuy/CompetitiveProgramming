#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

struct day {
    int fn;
    int idx;
    vector<int> friends;
    day(vector<int> frs, int id) {
        idx = id;
        fn = frs.size();
        friends = frs;
    }
};

bool cmp(day d1, day d2) {
    return d1.fn < d2.fn;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m, k, fi;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<day> days;
        vector<int> co(n, 0), ans(m, -1);
        for (int i = 0; i < m; i++) {
            cin >> k;
            vector<int> friends;
            while (k--) {
                cin >> fi;
                friends.push_back(fi - 1);
                co[fi - 1]++;
            }
            days.push_back(day(friends, i));
        }
        sort(days.begin(), days.end(), cmp);
        int f = -1;
        for (int i = 0; i < n; i++) {
            if (co[i] > (m / 2) + (m % 2)) {
                f = i;
                break;
            }
        }
        co.assign(n, 0);
        bool iok = true;
        for (int i = 0; i < m; i++) {
            int t1 = -1, t2 = -1;
            vector<int> frs = days[i].friends;
            for (int j = 0; j < frs.size(); j++) {
                if (frs[j] == f && co[f] < (m / 2) + (m % 2))
                    t2 = f;
                if (frs[j] != f && co[frs[j]] < (m / 2) + (m % 2)) {
                    t1 = frs[j];
                    break;
                }
            }
            if (t1 < 0 && t2 < 0) {
                iok = false;
                break;
            } else {
                if (t1 >= 0) {
                    ans[days[i].idx] = t1;
                    co[t1]++;
                } else {
                    ans[days[i].idx] = t2;
                    co[t2]++;
                }
            }
        }
        if (!iok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < m; i++)
            cout << ans[i] + 1 << ' ';
        cout << endl;
    }

    return 0;
}
