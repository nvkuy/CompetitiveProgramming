#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    int j = -1;
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        while (j + 1 < n && b[j + 1] >= a[i]) j++;
        ans *= max(1LL * j - i + 1, 0LL);
    }

    cout << ans << endl;

    return 0;
}