#include <bits/stdc++.h>

using namespace std;

long long f[1000001][10];
int dd[10];
vector<int> p;

int main()
{

    memset(dd, false, sizeof(dd));
    int x, n, t;
    cin >> x >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (!dd[t]) {
            p.push_back(t);
            dd[t] = true;
        }
    }
    for (int i = 0; i < p.size(); i++)
        f[0][i] = 1;
    sort(p.begin(), p.end());
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < p.size(); j++) {
            f[i][j] = 0;
            if (j > 0)
                f[i][j] = f[i][j - 1];
            if (i >= p[j])
                f[i][j] += f[i - p[j]][j];
        }
    }

    cout << f[x][p.size() - 1];

    return 0;
}
