#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        vector<pair<int, int>> rs;
        for (int i = 0; i < n; i++)
            rs.push_back(make_pair(a[i], b[i]));
        sort(rs.begin(), rs.end());
        for (int i = 0; i < rs.size(); i++) {
            if (k >= rs[i].first)
                k +=rs[i].second;
            else
                break;
        }
        cout << k << endl;
    }

    return 0;
}
