#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, ss;
    cin >> n;
    if ((n * (n + 1)) % 4 > 0) {
        cout << "NO";
        return 0;
    }
    long long setsum = (n * (n + 1)) / 4, cs = 0;
    vector<bool> dd(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cs += i;
        dd[i] = true;
        if (cs >= setsum) {
            dd[cs - setsum] = false;
            ss = i - 1;
            if (cs - setsum == 0)
                ss++;
            break;
        }
    }
    cout << "YES\n";
    cout << ss << endl;
    for (int i = 1; i <= n; i++) {
        if (dd[i])
            cout << i << ' ';
    }
    cout << endl;
    cout << n - ss << endl;
    for (int i = 1; i <= n; i++) {
        if (!dd[i])
            cout << i << ' ';
    }

    return 0;
}
