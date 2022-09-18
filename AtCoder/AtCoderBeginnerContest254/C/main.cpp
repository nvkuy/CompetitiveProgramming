#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<multiset<int>> modK(k);
    multiset<int>::iterator it;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        modK[i % k].insert(a[i]);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        it = modK[i % k].find(a[i]);
        if (it == modK[i % k].end()) {
            cout << "No";
            return 0;
        }
        modK[i % k].erase(it);
    }
    cout << "Yes";

    return 0;
}
