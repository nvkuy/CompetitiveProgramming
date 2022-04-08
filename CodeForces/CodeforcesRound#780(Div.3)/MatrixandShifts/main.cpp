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
        vector<vector<bool>> c(n, vector<bool>(n, false));
        vector<int> co(n, 0);
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == '0')
                    continue;
                c[i][j] = true;
                co[i]++;
            }
        }
        int minCost = n * n;
        for (int i = 0; i < n; i++) {
            int curCost = 0, tmp, row;
            for (int j = 0; j < n; j++) {
                row = (i + j) % n, tmp = co[row];
                if (c[row][j])
                    tmp--;
                else
                    tmp++;
                curCost += tmp;
            }
            minCost = min(minCost, curCost);
        }
        cout << minCost << endl;
    }

    return 0;
}
