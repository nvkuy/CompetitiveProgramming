#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, m, r, c, cc;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> m >> r >> c;
        vector<string> a;
        cin.ignore();
        for (int i = 0; i < n; i++) {
            s.clear();
            getline(cin, s);
            a.push_back(s);
        }
        if (a[r - 1][c - 1] == 'B')
            cout << "0\n";
        else {
            cc = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == 'B') {
                        cc++;
                        if (i + 1 == r || j + 1 == c) {
                            cc = -1;
                            break;
                        }
                    }
                }
                if (cc < 0)
                    break;
            }
            if (cc == 0)
                cout << "-1\n";
            else if (cc < 0)
                cout << "1\n";
            else
                cout << "2\n";
        }
    }

    return 0;
}
