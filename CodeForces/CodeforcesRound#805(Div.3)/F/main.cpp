#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, int> a, b;
        map<int, int>::iterator it;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            while (ai % 2 == 0)
                ai /= 2;
            a[ai]++;
        }
        for (int i = 0; i < n; i++) {
            cin >> ai;
            while (ai % 2 == 0)
                ai /= 2;
            b[ai]++;
        }
        bool iok = true;
        for (it = b.begin(); it != b.end(); it++) {
            int num = it->first, rem = it->second;
            while (rem > 0 && num > 0) {
                while (num > 0 && a[num] == 0)
                    num /= 2;
                int has = a[num];
                int use = min(has, rem);
                a[num] -= use, rem -= use;
            }
            if (rem > 0) {
                iok = false;
                break;
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
