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
        int n = s.length();
        int lastOne = 0, firstZero = n - 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                lastOne = i;
            if (s[i] == '0')
                firstZero = min(firstZero, i);
        }
        cout << firstZero - lastOne + 1 << endl;
    }

    return 0;
}
