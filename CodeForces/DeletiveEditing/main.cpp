#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    string s1, s2;
    cin >> n;
    while (n--) {
        vector<int> cnt(33, 0);
        cin >> s1 >> s2;
        for (int i = 0; i < s2.length(); i++)
            cnt[s2[i] - 'A']++;
        int k = s2.length() - 1;
        for (int i = s1.length() - 1; i >= 0; i--) {
            if (k < 0)
                break;
            if (s1[i] == s2[k]) {
                k--;
                cnt[s1[i] - 'A']--;
                continue;
            }
            if (cnt[s1[i] - 'A'] > 0) {
                //cout << "TEST: " << i << '|' << k << endl;
                break;
            }

        }
        cout << ((k < 0) ? "YES" : "NO") << endl;
    }

    return 0;
}
