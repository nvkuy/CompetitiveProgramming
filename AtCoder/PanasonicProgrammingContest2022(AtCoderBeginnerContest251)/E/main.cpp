#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vector<long long> a;

long long costIfChooseI(int s) {
    long long pf1 = a[s], pf2 = 1e18, f1, f2;
    for (int i = ((s + 1) % n); i != s; i = ((i + 1) % n)) {
        f2 = pf1;
        f1 = min(pf1 + a[i], pf2 + a[i]);
        pf1 = f1, pf2 = f2;
    }
    return min(pf1, pf2);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long ans = min(costIfChooseI(0), costIfChooseI(1));
    if (n > 2)
        ans = min(ans, costIfChooseI(2));
    cout << ans;

    return 0;
}
