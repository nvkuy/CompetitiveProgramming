#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, k, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        map<int, int> first, last;
        for (int i = 0; i < n; i++)
            first.insert(make_pair(arr[i], i));
        for (int i = n - 1; i >= 0; i--)
            last.insert(make_pair(arr[i], i));
        while (k--) {
            cin >> a >> b;
            bool iok = true;
            if (first.find(a) == first.end() || last.find(b) == last.end())
                iok = false;
            else {
                int p1 = first[a], p2 = last[b];
                if (p1 > p2)
                    iok = false;
            }
            cout << (iok ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
