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
        vector<int> cnt(33, 0);
        for (int i = 0; i < s.length(); i++)
            cnt[s[i] - 'a']++;
        int k = 0, nc = 0;
        for (int i = 0; i < 33; i++) {
            if (cnt[i] > 1) {
                k++;
                continue;
            }
            if (cnt[i] > 0)
                nc++;
        }
        k += (nc / 2);
        cout << k << endl;
    }

    return 0;
}
