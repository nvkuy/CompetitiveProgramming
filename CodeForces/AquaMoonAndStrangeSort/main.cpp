#include <bits/stdc++.h>

using namespace std;

int dd1[100001], dd2[100001];

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        memset(dd1, 0, sizeof(dd1));
        memset(dd2, 0, sizeof(dd2));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i % 2)
                dd1[a[i]]++;
            else
                dd2[a[i]]++;
        }
        sort(a.begin(), a.end());
        bool iok = true;
        for (int i = 0; i < n; i++) {
            if (i % 2)
                dd1[a[i]]--;
            else
                dd2[a[i]]--;
            if (dd1[a[i]] < 0 || dd2[a[i]] < 0) {
                iok = false;
                break;
            }
        }
        cout << (iok ? "YES" : "NO") << '\n';
    }

    return 0;
}
