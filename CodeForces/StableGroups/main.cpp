#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long n, k, x, need;
    cin >> n >> k >> x;
    vector<long long> a(n), diff(n - 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
        diff[i] = a[i + 1] - a[i];
    }
    sort(diff.begin(), diff.end(), greater<long long>());
    for (int i = n - 2; i >= 0; i--) {
        if (diff[i] <= x)
            diff.pop_back();
        else {
            need = diff[i] / x;
            if (diff[i] % x > 0)
                need++;
            need--;
            if (need > k)
                break;
            else {
                k -= need;
                diff.pop_back();
            }
        }
    }
    cout << diff.size() + 1;

    return 0;
}
