#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x, ans = 0;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    while (i < j) {
        if (a[i] + a[j] <= x) {
            ans++;
            i++, j--;
        } else {
            j--;
            ans++;
        }
    }
    if (i == j)
        ans++;
    cout << ans;

    return 0;
}
