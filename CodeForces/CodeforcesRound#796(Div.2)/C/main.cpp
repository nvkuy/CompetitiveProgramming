#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        vector<int> cnt(33, 0);
        for (int i = 0; i <= 2 * n; i++) {
            getline(cin, s);
            for (int j = 0; j < s.length(); j++)
                cnt[s[j] - 'a']++;
        }
        for (int i = 0; i < 33; i++) {
            if (cnt[i] % 2)
                cout << (char)(i + 'a') << endl;
        }
    }

    return 0;
}
