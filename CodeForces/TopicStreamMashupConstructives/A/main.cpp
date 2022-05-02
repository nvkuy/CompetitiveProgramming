#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    string s;
    cin >> n;
    while (s.length() < n)
        s += "aabb";
    for (int i = 0; i < n; i++)
        cout << s[i];

    return 0;
}
