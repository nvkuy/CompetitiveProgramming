#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> a(4);
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    cout << a[0] * a[2];

    return 0;
}
