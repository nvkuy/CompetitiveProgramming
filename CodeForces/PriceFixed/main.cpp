#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long s = 0LL, n, a, b;
    cin >> n;
    vector<pair<long long, long long>> arr;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr.push_back(make_pair(b, a));
        s += a;
    }
    sort(arr.begin(), arr.end());
    long long j = 0LL, i = 0LL, ans = 0LL;
    while (true) {
        if (i >= arr[j].first) {
            if (s >= arr[j].second) {
                s -= arr[j].second;
                i += arr[j].second;
                ans += arr[j].second;
            } else {
                i += s;
                ans += s;
                s = 0LL;
            }
            j++;
            if (s <= 0)
                break;
        } else {
            if (s >= (arr[j].first - i)) {
                s -= (arr[j].first - i);
                ans += ((arr[j].first - i) * 2);
                i = arr[j].first;
            } else {
                ans += (s * 2);
                i += s;
                s = 0LL;
            }
            if (s >= arr[j].second) {
                s -= arr[j].second;
                i += arr[j].second;
                ans += arr[j].second;
            } else {
                i += s;
                ans += s;
                s = 0LL;
            }
            j++;
            if (s <= 0)
                break;
        }
    }
    cout << ans;

    return 0;
}
