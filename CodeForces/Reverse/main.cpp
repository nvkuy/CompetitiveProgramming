#include <bits/stdc++.h>

using namespace std;

long long bm(long long x, int &i) {
    if (x > 0) {
        long long ans = bm(x / 2, i) + (x % 2) * pow(2, i);
        i++;
        return ans;
    }
    return 0LL;
}

int main()
{
    int mm = 1001;
    long long x, y, tmp;
    cin >> x >> y;
    set<long long> dd;
    queue<pair<long long, int>> q;
    q.push(make_pair(x, 0));
    dd.insert(x);
    bool iok = false;
    while (!q.empty()) {
        pair<long long, int> pt = q.front();
        q.pop();
        if (pt.first == y) {
            iok = true;
            break;
        }
        if (pt.second > mm)
            continue;
        int i = 0;
        tmp = bm(pt.first, i);
        if (dd.find(tmp) == dd.end()) {
            q.push(make_pair(tmp, pt.second + 1));
            dd.insert(tmp);
        }
        if (pt.first <= 1e18) {
            i = 0;
            tmp = bm(pt.first * 2 + 1, i);
            if (dd.find(tmp) == dd.end()) {
                q.push(make_pair(tmp, pt.second + 1));
                dd.insert(tmp);
            }
        }
    }
    cout << (iok ? "YES" : "NO") << endl;

    return 0;
}
