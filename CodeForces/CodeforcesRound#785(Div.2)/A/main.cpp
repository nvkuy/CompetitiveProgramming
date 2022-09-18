#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        //cout << s << endl;
        int ss = 0, n = s.length();
        for (int i = 0; i < n; i++)
            ss += (s[i] - 'a' + 1);
        if (n == 1) {
            cout << "Bob " << ss << endl;
            continue;
        }
        if (n % 2)
            ss -= 2 * (min(s[0] - 'a', s[n - 1] - 'a') + 1);
        cout << "Alice " << ss << endl;
    }

    return 0;
}
