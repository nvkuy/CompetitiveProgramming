#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x;
    map<int, pair<int, int>> dd;
    map<int, pair<int, int>>::iterator it;

    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            it = dd.find(x - a[i] - a[j]);
            if (it != dd.end()) {
                pair<int, int> tmp = it->second;
                cout << i + 1 << ' ' << j + 1 << ' ' << tmp.first << ' ' << tmp.second;
                return 0;
            }
        }
        for (int j = 0; j < i; j++)
            dd.insert(make_pair(a[j] + a[i], make_pair(j + 1, i + 1)));
    }
    cout << "IMPOSSIBLE";


    return 0;
}
