#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ai;
    multiset<int> dd;
    multiset<int>::iterator it;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        it = dd.upper_bound(ai);
        if (it != dd.end())
            dd.erase(it);
        dd.insert(ai);
    }
    cout << dd.size();

    return 0;
}
