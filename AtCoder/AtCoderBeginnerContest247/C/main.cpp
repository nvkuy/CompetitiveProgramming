#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    string s = "1";
    cin >> n;
    for (int i = 2; i <= n; i++)
        s = (s + " " + to_string(i) + " " + s);
    cout << s;

    return 0;
}
