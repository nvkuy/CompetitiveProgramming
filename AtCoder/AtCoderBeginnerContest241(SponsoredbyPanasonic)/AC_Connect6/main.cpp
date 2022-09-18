#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<bool>> c(n, vector<bool>(n, false));
    string s;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (int j = 0; j <= n; j++)
            if (s[j] == '#')
                c[i][j] = true;
    }
    //hor
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - 6; j++) {
            int co = 0;
            for (int k = j; k < j + 6; k++)
                co += c[i][k];
            if (co >= 4) {
                cout << "Yes";
                return 0;
            }
        }
    }
    //ver
    for (int i = 0; i <= n - 6; i++) {
        for (int j = 0; j < n; j++) {
            int co = 0;
            for (int k = i; k < i + 6; k++)
                co += c[k][j];
            if (co >= 4) {
                cout << "Yes";
                return 0;
            }
        }
    }
    //dia
    for (int i = 0; i <= n - 6; i++) {
        for (int j = 0; j <= n - 6; j++) {
            int co = 0;
            for (int k = 0; k < 6; k++)
                co += c[i + k][j + k];
            if (co >= 4) {
                cout << "Yes";
                return 0;
            }
        }
    }
    for (int i = 0; i <= n - 6; i++) {
        for (int j = 5; j < n; j++) {
            int co = 0;
            for (int k = 0; k < 6; k++)
                co += c[i + k][j - k];
            if (co >= 4) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";

    return 0;
}
