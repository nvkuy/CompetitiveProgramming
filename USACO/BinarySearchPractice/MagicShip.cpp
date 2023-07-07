#include <bits/stdc++.h>
using namespace std;

int main() {

    long long x1, y1, x2, y2, n;
    string s;
    cin >> x1 >> y1 >> x2 >> y2 >> n >> s;
    long long l = 0, r = 1e13, m;
    while (l < r) {
        m = (l + r) / 2;
        map<char, long long> cnt;
        for (int i = 0; i < n; i++) {
            cnt[s[i]] += (m / n);
            if ((m % n) > i)
                cnt[s[i]]++;
        }
        long long nx = x1 - (cnt['L'] - cnt['R']), ny = y1 - (cnt['D'] - cnt['U']);
        if (abs(nx - x2) + abs(ny - y2) <= m)
            r = m;
        else
            l = m + 1;
    }
    if (r > n * n)
        r = -1;
    cout << r << endl;

    return 0;
}