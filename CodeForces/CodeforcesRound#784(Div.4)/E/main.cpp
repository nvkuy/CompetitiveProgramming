#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    map<string, int> cnt;
    int t, n;
    cin >> t;
    while (t--) {
        cnt.clear();
        cin >> n;
        cin.ignore();
        vector<string> a(n);
        for (int i = 0; i < n; i++)
            getline(cin, a[i]);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
            string tmp;
            for (char c = 'a'; c <= 'k'; c++) {
                tmp.clear();
                tmp.push_back(a[i][0]), tmp.push_back(c);
                if (tmp != a[i])
                    ans += cnt[tmp];
                tmp.clear();
                tmp.push_back(c), tmp.push_back(a[i][1]);
                if (tmp != a[i])
                    ans += cnt[tmp];
            }
        }
        cout << ans << endl;
    }

    return 0;
}
