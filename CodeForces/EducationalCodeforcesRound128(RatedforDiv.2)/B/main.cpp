#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cin.ignore();
        vector<string> mm(n);
        for (int i = 0; i < n; i++)
            getline(cin, mm[i]);
        int min_x = n - 1, min_y = m - 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mm[i][j] == 'R') {
                    min_x = min(min_x, i);
                    min_y = min(min_y, j);
                }
            }
        }
        cout << ((mm[min_x][min_y] == 'R') ? "YES" : "NO") << endl;
    }

    return 0;
}
