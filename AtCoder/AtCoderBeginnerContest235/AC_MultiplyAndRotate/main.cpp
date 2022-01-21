#include <bits/stdc++.h>

using namespace std;

int dd[10000001];

int main()
{
    long long a, n;
    cin >> a >> n;
    queue<long long> q;
    //vector<int> dd(n * 11, -1);
    memset(dd, -1, sizeof(dd));
    q.push(1);
    dd[1] = 0;
    dd[0] = 0;
    while (!q.empty()) {
        long long u = q.front();
        q.pop();
        if (u == n)
            break;
        if (u * a < n * 10) {
            if (dd[u * a] < 0) {
                q.push(u * a);
                dd[u * a] = dd[u] + 1;
            }
        }
        if (u < 10 || u % 10 == 0 || u > 10 * n)
            continue;
        long long v = 1;
        while (u >= v)
            v *= 10;
        v *= (u % 10);
        v = (v + u) / 10;
        if (dd[v] < 0) {
            q.push(v);
            dd[v] = dd[u] + 1;
        }
    }
    cout << dd[n];

    return 0;
}
