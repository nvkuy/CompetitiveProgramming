#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, r, b;
    cin >> t;
    while (t--) {
        cin >> n >> r >> b;
        vector<int> a(b + 1);
        for (int i = 0; i < a.size(); i++)
            a[i] = (r / (b + 1));
        r %= (b + 1);
        for (int i = 0; i < a.size(); i++) {
            if (r <= 0)
                break;
            r--;
            a[i]++;
        }
        while (a[0]--)
            cout << 'R';
        for (int i = 1; i < a.size(); i++) {
            cout << 'B';
            while (a[i]--)
                cout << 'R';
        }
        cout << endl;
    }

    return 0;
}
