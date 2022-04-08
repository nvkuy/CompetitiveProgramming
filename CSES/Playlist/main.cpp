#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ans = 0;
    cin >> n;

    set<int> dd;
    vector<int> a(n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (dd.find(a[i]) != dd.end()) {
            dd.erase(dd.find(a[j]));
            j++;
        }
        dd.insert(a[i]);
        ans = max(ans, i - j + 1);
    }
    cout << ans;

    return 0;
}
