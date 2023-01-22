#include <bits/stdc++.h>
using namespace std;

int main() {

    if (fopen("stacking.in", "r")) {
        freopen("stacking.in", "r", stdin);
        freopen("stacking.out", "w", stdout);
    }

    int n, k;
    cin >> n >> k;
    vector<int> ps(n + 2, 0);
    while (k--) {
        int l, r;
        cin >> l >> r;
        ps[l]++;
        ps[r + 1]--;
    }
    for (int i = 1; i <= n; i++)
        ps[i] += ps[i - 1];
    sort(ps.begin() + 1, ps.begin() + n + 1);
    cout << ps[(n + 1) / 2] << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << ps[i] << endl;

    return 0;
}