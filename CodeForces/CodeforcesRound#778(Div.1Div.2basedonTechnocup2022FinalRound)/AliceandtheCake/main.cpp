#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int n;
map<long long, int> co;
map<long long, int>::iterator it;

void check(long long s) {
    if (co[s] > 0) {
        co[s]--;
        return;
    }
    if (s <= (*co.begin()).first || n <= 1)
        return;
    n--;
    if (s % 2 == 0) {
        check(s / 2LL);
        check(s / 2LL);
    } else {
        check(s / 2LL);
        check((s / 2LL) + 1LL);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        co.clear();
        long long s = 0LL;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
            co[a[i]]++;
        }
        check(s);
        bool iok = true;
        for (it = co.begin(); it != co.end(); it++) {
            if ((*it).second > 0) {
                iok = false;
                break;
            }
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
