#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> par;

int root(int v) {
    return par[v] < 0 ? v : (par[v] = root(par[v]));
}

void mergeSet(int x, int y) {
    if ((x = root(x)) == (y = root(y)))
        return ;
    if (par[y] < par[x])
        swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        par.assign(n, -1);
        vector<int> a(n), roots;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (a[i] & a[j] > 0)
                    mergeSet(i, j);
        for (int i = 0; i < n; i++)
            if (par[i] < 0)
                roots.push_back(i);
        int cost = 0;
        if (roots.size() > 1) {
            for (int i = 0; i < roots.size(); i++) {
                if (a[roots[i]] % 2 == 0) {
                    a[roots[i]]++;
                    cost++;
                }
            }
        }
        cout << cost << endl;
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << endl;
    }

    return 0;
}
