#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    string ans;
    cin >> n;
    ans = to_string(n % 100);
    while (ans.length() < 2)
        ans = '0' + ans;
    cout << ans;

    return 0;
}
