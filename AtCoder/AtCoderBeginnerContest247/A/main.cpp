#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    for (int i = s.length() - 2; i >= 0; i--)
        s[i + 1] = s[i];
    s[0] = '0';
    cout << s;

    return 0;
}
