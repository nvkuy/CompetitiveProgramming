#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> c;
map<int, int> dd1, dd2;
map<int, int>::iterator it1, it2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> m;
    c.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> n;
        c[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
            it1 = dd1.find(c[i][j]);
            if (it1 == dd1.end())
                dd1.insert(make_pair(c[i][j], 1));
            else
                (it1->second)++;
        }
    }
    for (it1 = dd1.begin(); it1 != dd1.end(); it1++) {
        if ((*it1).second % 2) {
            cout << "NO";
            return 0;
        }
        (it1->second) /= 2;
        dd2.insert(make_pair((*it1).first, (*it1).second));
    }
    cout << "YES\n";
    bool irg = false;
    for (int i = 0; i < m; i++) {
        int k = c[i].size() / 2;
        for (int j = 0; j < c[i].size(); j++) {
            it1 = dd1.find(c[i][j]);
            it2 = dd2.find(c[i][j]);
            if (((*it1).second <= 0) || (k <= 0)) {
                cout << 'L';
                (it2->second)--;
            } else {
                if ((*it2).second == (*it1).second) {
                    if (irg) {
                        cout << 'L';
                        (it2->second)--;
                        irg = false;
                    } else {
                        cout << 'R';
                        (it1->second)--;
                        k--;
                        irg = true;
                    }
                }
                else if ((*it2).second > (*it1).second) {
                    cout << 'L';
                    (it2->second)--;
                } else {
                    cout << 'R';
                    (it1->second)--;
                    k--;
                }
            }
        }
        cout << '\n';
    }

    return 0;
}
