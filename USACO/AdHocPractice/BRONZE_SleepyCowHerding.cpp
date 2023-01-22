#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    int min_ans = 1e9, max_ans = 0;
    if (a[0] + 1 == a[1] && a[1] + 1 == a[2])
        min_ans = 0;
    else if (a[0] + 2 == a[1] || a[1] + 2 == a[2])
        min_ans = 1;
    else
        min_ans = 2;
    max_ans = max(a[2] - a[1], a[1] - a[0]) - 1;
    cout << min_ans << endl << max_ans << endl;

    return 0;
}