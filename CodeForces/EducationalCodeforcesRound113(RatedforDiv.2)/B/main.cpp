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
        vector<vector<int>> ans(n, vector<int>(n, 0)); //0 == x,1 == +, 2 == -, 3 == =
        cin.ignore();
        getline(cin, s);
        vector<int> type2;
        for (int i = 0; i < n; i++) {
            if (s[i] == '2')
                type2.push_back(i);
        }
        if (type2.size() > 0 && type2.size() < 3) {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i < type2.size(); i++) {
            int u = type2[i], v = type2[(i + 1) % type2.size()];
            ans[u][v] = 1, ans[v][u] = 2;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && ans[i][j] == 0)
                    ans[i][j] = 3;
            }
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ans[i][j] == 0)
                    cout << 'X';
                else if (ans[i][j] == 1)
                    cout << '+';
                else if (ans[i][j] == 2)
                    cout << '-';
                else
                    cout << '=';
            }
            cout << endl;
        }
    }

    return 0;
}
