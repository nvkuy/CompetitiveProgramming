#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << "1 3 2 ";
        for (int i = 4; i <= n; i++)
            cout << i << ' ';
        cout << endl;
        vector<int> a;
        for (int i = 2; i <= n; i++)
            a.push_back(i);
        for (int i = 2; i <= n; i++)
            a.push_back(i);
        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < i + n - 1; j++)
                cout << a[j] << ' ';
            cout << "1\n";
        }
    }

    return 0;
}
