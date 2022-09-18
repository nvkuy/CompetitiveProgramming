#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k, mt = 0, ai;
    cin >> n >> k;
    set<int> dd;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mt = max(mt, a[i]);
    }
    while (k--) {
        cin >> ai;
        dd.insert(ai);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == mt && dd.find(i + 1) != dd.end()) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";

    return 0;
}
