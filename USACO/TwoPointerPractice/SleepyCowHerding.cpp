#include <bits/stdc++.h>
using namespace std;

int main() {

    if (fopen("herding.in", "r")) {
        freopen("herding.in", "r", stdin);
        freopen("herding.out", "w", stdout);
    }

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int min_ans = n;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (a[i] - a[j] + 1 > n)
            j++;
        int tans = n - (i - j + 1);
        if (i - j + 1 == n - 1 && a[i] - a[j] == i - j)
            tans++;
        min_ans = min(min_ans, tans);
    }
    int max_ans = 0;
    for (int i = 1; i < n; i++) max_ans += a[i] - a[i - 1] - 1;
    max_ans -= min(a[1] - a[0], a[n - 1] - a[n - 2]) - 1;
    cout << min_ans << endl << max_ans << endl;

    return 0;
}
