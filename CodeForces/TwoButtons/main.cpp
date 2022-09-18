#include <bits/stdc++.h>

using namespace std;

bool c[10001][20002];
int dd[20002];

int main()
{

    int n, m, u;
    cin >> n >> m;
    if (n >= m) {
        cout << n - m;
        return 0;
    }
    for (int i = 0; i <= m; i++) {
        c[i][i * 2] = true;
        c[i + 1][i] = true;
    }
    memset(dd, 0, sizeof(dd));
    queue<int> q;
    q.push(n);
    dd[n] = 1;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        if (u == m) {
            cout << dd[u] - 1;
            break;
        }
        if ((dd[u - 1] == 0) && (u > 1)) {
            q.push(u - 1);
            dd[u - 1] = dd[u] + 1;
        }
        if ((dd[u * 2] == 0) && (u <= m)) {
            q.push(u * 2);
            dd[u * 2] = dd[u] + 1;
        }
    }
    /*
    if (n >= m) {
        cout << n - m;
        return 0;
    }
    while (m > n) {
        if (m % 2) {
            m++;
            c++;
        } else {
            m /= 2;
            c++;
        }
    }
    cout << c + (n - m);
    */

    return 0;
}
