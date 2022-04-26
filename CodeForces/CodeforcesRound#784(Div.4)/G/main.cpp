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
        vector<string> c(n + 1);
        for (int i = 0; i < n; i++)
            getline(cin, c[i]);
        for (int i = 0; i < m; i++)
            c[n].push_back('o');
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] != '*')
                    continue;
                int k = i;
                while (c[k + 1][j] == '.') {
                    swap(c[k + 1][j], c[k][j]);
                    k++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << c[i][j];
            cout << endl;
        }
    }

    return 0;
}
