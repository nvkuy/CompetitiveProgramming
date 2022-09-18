#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool check(string n) {
    string tmp = n;
    reverse(tmp.begin(), tmp.end());
    long long rvn = stoll(tmp);
    if (rvn == 1LL)
        return false;
    for (long long i = 2; i * i <= rvn; i++) {
        if (rvn % i == 0)
            return false;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long t;
    string n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (check(n) ? "Yes" : "No") << endl;
    }

    return 0;
}
