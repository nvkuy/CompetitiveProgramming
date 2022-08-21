#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int maxN = 4;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<vector<int>> c(maxN, vector<int>(maxN, 0));
    string s;
    for (int i = 0; i < maxN; i++) {
        cin >> s;
        for (int j = 0; j < maxN; j++) {
            if (s[j] == '#')
                c[i][j] = 1;
        }
    }
    for (int i = 0; i + 1 < maxN; i++) {
        for (int j = 0; j + 1 < maxN; j++) {
            int ss = c[i][j] + c[i][j + 1] + c[i + 1][j] + c[i + 1][j + 1];
            if (ss <= 1 || ss >= 3) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";

    return 0;
}
