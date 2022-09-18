#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        b.push_back(0);
        for (int i = 0; i < n; i++) {
            vector<int> tmp = b;
            for (int j = 0; j < b.size(); j++)
                tmp.push_back(b[j] + a[i]);
            b = tmp;
        }
        sort(b.begin(), b.end());
        bool iok = false;
        for (int i = 1; i < b.size(); i++) {
            if (b[i] == b[i - 1]) {
                iok = true;
                break;
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
