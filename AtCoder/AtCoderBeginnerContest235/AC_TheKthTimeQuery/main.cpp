#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, k, x;
    cin >> n >> q;
    vector<vector<int>> dd(n + 1);
    map<int, int> mmap;
    map<int, int>::iterator it;
    k = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        it = mmap.find(x);
        if (it == mmap.end()) {
            mmap.insert(pair<int, int>(x, k));
            dd[k].push_back(i);
            k++;
        } else {
            pair<int, int> p = *it;
            dd[p.second].push_back(i);
        }
    }
    while (q--) {
        cin >> x >> k;
        it = mmap.find(x);
        if (it == mmap.end()) {
            cout << "-1\n";
            continue;
        }
        pair<int, int> p = *it;
        if (dd[p.second].size() < k) {
            cout << "-1\n";
            continue;
        }
        cout << dd[p.second][k - 1] + 1 << '\n';
    }

    return 0;
}
