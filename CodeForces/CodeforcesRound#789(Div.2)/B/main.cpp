#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        char pre = s[0];
        int c = 0, ans = 0, cpyans;
        vector<pair<int, pair<int, int>> seg;
        for (int i = 0; i < n; i++) {
            if (s[i] != pre) {
                seg.push_back({c, {i - c + 1, i});
                if (c % 2) {
                    s[i] = pre;
                    c++;
                    ans++;
                } else {
                    pre = s[i];
                    c = 1;
                }
            } else {
                c++;
                if (i + 1 >= n)
                    seg.push_back({c, {i - c + 1, i});
            }
        }
        cpyans = ans;
        sort(seg.begin(), seg.end(), greater<int>());
        while (seg.back().first <= cpyans) {
            cpyans -= seg.back().first;
            pair<int, int> tmp = seg.back().second;
            for (int i = tmp.first; i <= tmp.second; i++)
                s[i] = (s[i] == '0' ? '1' : '0');
            seg.pop_back();
        }
        cout << ans << ' ' << seg.size() << endl;
    }

    return 0;
}
