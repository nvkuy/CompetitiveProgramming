#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        bool iok = true;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i] == a[j]) iok = false;
        for (int p = 2; p <= n / 2; p++) {
            map<int, int> cnt;
            for (int i = 0; i < n; i++)
                cnt[a[i] % p]++;
            bool canChoose = false;
            for (int i = 0; i < p; i++)
                canChoose |= (cnt[i] < 2);
            iok &= canChoose;
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
