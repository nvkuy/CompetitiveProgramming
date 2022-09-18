#include <bits/stdc++.h>

using namespace std;

vector<vector<short>> s;
//vector<int> iq;
vector<short> ans;

int query(int l, int r) {
    int tmp, qs = 0;
    //iq.clear();
    for (int i = l; i <= r; i++) {
        qs += s[i].size();
        //for (int j = 0; j < s[i].size(); j++)
        //    iq.push_back(s[i][j]);
    }
    cout << "? " << qs;
    for (int i = l; i <= r; i++)
        for (int j = 0; j < s[i].size(); j++)
            cout << ' ' << s[i][j];
    //for (int i = 0; i < iq.size(); i++)
    //    cout << ' ' << iq[i];
    cout << endl;
    cout.flush();
    cin >> tmp;
    return tmp;
}

int main()
{
    int n, k, c, t, am;
    string rp;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        s.clear();
        s.resize(k + 1);
        for (int i = 1; i <= k; i++) {
            cin >> c;
            int j;
            while (c--) {
                cin >> j;
                s[i].push_back(j);
            }
        }
        cout << "? " << n;
        for (int i = 1; i <= n; i++)
            cout << ' ' << i;
        cout << endl;
        cout.flush();
        cin >> am;
        int l = 1, r = k, m, t1, t2;
        ans.resize(k + 1);
        while (l <= r) {
            if (l == r) {
                if (l == k) {
                    t1 = query(1, l - 1);
                    if (t1 == -1)
                        break;
                    ans[l] = t1;
                } else {
                    t1 = query(l + 1, n);
                    if (t1 == -1)
                        break;
                    ans[l] = t1;
                }
                break;
            }
            m = (l + r) / 2;
            t1 = query(l, m);
            if (t1 == -1)
                break;
            t2 = query(m + 1, r);
            if (t2 == -1)
                break;
            if ((t1 == am && t2 == am) || (t1 < am && t2 < am)) {
                for (int i = l; i <= r; i++)
                    ans[i] = am;
                break;
            }
            if (t1 < am) {
                for (int i = l; i <= m; i++)
                    ans[i] = am;
                l = m + 1;
            }
            if (t2 < am) {
                for (int i = m + 1; i <= r; i++)
                    ans[i] = am;
                r = m;
            }
        }
        if (t1 == -1 || t2 == -1)
            break;
        cout << '!';
        for (int i = 1; i <= k; i++)
            cout << ' ' << ans[i];
        cout << endl;
        cout.flush();
        getline(cin, rp);
        if (rp == "Incorrect")
            break;
    }

    return 0;
}
