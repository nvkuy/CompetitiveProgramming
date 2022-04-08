#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("test_input12.txt", "r", stdin);

    long long n, i1, i2, i3, x, ai;
    i1 = i2 = i3 = -1;

    cin >> n >> x;
    vector<pair<long long, int>> a;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        a.push_back(make_pair(ai, i));
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (n - i <= 2 || i1 >= 0)
            break;
        int k = n - 1;
        for (int j = i + 1; j < n; j++) {
            while ((k > j) && ((a[i].first + a[j].first + a[k].first) > x))
                k--;
            if (k <= j || i1 >= 0)
                break;
            if (a[i].first + a[j].first + a[k].first == x) {
                i1 = a[i].second;
                i2 = a[j].second;
                i3 = a[k].second;
                break;
            }
        }
    }
    if (i1 < 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << i1 + 1 << ' ' << i2 + 1 << ' ' << i3 + 1;

    return 0;
}
