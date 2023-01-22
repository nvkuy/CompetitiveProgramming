#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    
    int n;
    cin >> n;
    vector<int> a(n), sa;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sa = a;
    sort(sa.begin(), sa.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == sa[i])
            continue;
        int pos = -1;
        for (int j = i + 1; j < n; j++) {
            if (a[i] == sa[j] && sa[i] == a[j]) {
                pos = j;
                break;
            }
        }
        if (pos != -1) {
            swap(a[pos], a[i]);
            ans++;
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            if (a[j] == sa[i] && sa[j] != a[j]) {
                swap(a[i], a[j]);
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}