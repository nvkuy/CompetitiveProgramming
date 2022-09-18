#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> a;
vector<vector<int>> posx;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q, l, r, x;
    cin >> n;
    a.resize(n + 1);
    posx.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        posx[a[i]].push_back(i);
    }
    cin >> q;
    while (q--) {
        cin >> l >> r >> x;
        int i = lower_bound(posx[x].begin(), posx[x].end(), l) - posx[x].begin();
        int j = lower_bound(posx[x].begin(), posx[x].end(), r) - posx[x].begin();
        if (j == posx[x].size())
            j--;
        while (j >= i && posx[x][j] > r)
            j--;
        //cout << "TEST: " << i << ' ' << j << endl;
        cout << max(j - i + 1, 0) << endl;
    }

    return 0;
}
