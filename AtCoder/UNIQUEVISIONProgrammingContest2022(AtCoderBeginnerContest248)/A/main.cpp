#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int ss = 0;
    string s;
    for (int i = 1; i <= 9; i++)
        ss += i;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
        ss -= (s[i] - '0');
    cout << ss;

    return 0;
}
