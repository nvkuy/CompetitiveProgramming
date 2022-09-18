#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ai, ce = 0;
    cin >> n;
    vector<int> a;
    a.push_back(ce);
    for (int i = 0; i < n; i++) {
        cin >> ai;
        ce = (ce + ai) % 360;
        //cout << ce << endl;
        a.push_back(ce);
    }
    sort(a.begin(), a.end());
    /*
    for (int i = 0; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;
    */
    ai = a[0] - a[n] + 360;
    for (int i = 0; i < n; i++)
        ai = max(ai, a[i + 1] - a[i]);
    cout << ai;

    return 0;
}
