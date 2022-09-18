#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), ans;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int i = 0;
        if (n % 2) {
            ans.push_back(a[i]);
            i++;
        }
        for (; i < n; i += 2) {
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
            ans.push_back(a[i]), ans.push_back(a[i + 1]);
        }
        bool iok = true;
        for (i = 1; i < n; i++)
            if (ans[i - 1] > ans[i])
                iok = false;
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
