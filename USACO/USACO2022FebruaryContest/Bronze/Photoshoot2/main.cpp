#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ans = 0;
    set<int> dd;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int j = 0;
    for (int i = 0; i < n; i++) {
        dd.insert(b[i]);
        if (a[j] != b[i])
            ans++;
        else {
            while (j < n && dd.find(a[j]) != dd.end())
                j++;
        }
    }
    cout << ans;

    return 0;
}
