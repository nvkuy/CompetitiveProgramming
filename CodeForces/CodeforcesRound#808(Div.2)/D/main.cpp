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
        vector<int> a(n), b;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        reverse(a.begin(), a.end());
        int numZero = 0;
        while (true) {
            while (a.size() > 1 && a.back() == 0) {
                numZero++;
                a.pop_back();
            }
            if (a.size() == 1)
                break;
            b.clear();
            if (numZero > 0) {
                b.push_back(a.back());
                numZero--;
            }
            for (int i = 0; i < a.size() - 1; i++)
                b.push_back(a[i] - a[i + 1]);
            sort(b.begin(), b.end(), greater<int>());
            a = b;
        }
        cout << a[0] << endl;
    }

    return 0;
}
