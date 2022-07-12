#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int na = n, nb = n;
    if (a[n - 1] == b[0]) {
        nb--;
        cout << 'b';
    }
    for (int i = 0; i < na; i++)
        cout << 'a';
    for (int i = 0; i < nb; i++)
        cout << 'b';

    return 0;
}
