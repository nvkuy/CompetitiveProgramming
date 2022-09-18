#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool check(long long ai) {
    string s = to_string(ai);
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long tt, a;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        cin >> a;
        long long ans = 0;
        for (long long i = 1; i * i <= a; i++) {
            if (a % i > 0)
                continue;
            if (check(i))
                ans++;
            if (i != (a / i) && check(a / i))
                ans++;
        }
        cout << "CASE #" << t << ": " << ans << endl;
    }

    return 0;
}
