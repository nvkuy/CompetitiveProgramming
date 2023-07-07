#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k, m, n;
    cin >> k >> m >> n;
    vector<pair<int, int>> a(k);
    vector<int> b(m);
    for (int i = 0; i < k; i++)
        cin >> a[i].first >> a[i].second;
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<long long> c;
    long long sum_val = 0;
    for (int i = 0; i < k; i++) {
        if (a[i].first >= b[0])
            break;
        sum_val += a[i].second; 
    }
    c.push_back(sum_val);
    sum_val = 0;
    for (int i = k - 1; i >= 0; i--) {
        if (a[i].first <= b[m - 1])
            break;
        sum_val += a[i].second; 
    }
    c.push_back(sum_val);
    int j = 0;
    for (int i = 1; i < m; i++) {
        long long all_sum = 0, best_sum = 0, cur_sum = 0;
        int l = j;
        while (j < k && a[j].first < b[i]) {
            if (a[j].first > b[i - 1]) {
                all_sum += a[j].second;
                cur_sum += a[j].second;
                while ((a[j].first - a[l].first + 1) > (b[i] - b[i - 1] + 1) / 2) {
                    cur_sum -= a[l].second;
                    l++;
                }
                best_sum = max(best_sum, cur_sum);
            } else
                l++;
            j++;
        }
        c.push_back(best_sum);
        c.push_back(all_sum - best_sum);
    }
    sort(c.begin(), c.end(), greater<long long>());
    long long ans = 0;
    for (int i = 0; i < min(n, (int)c.size()); i++)
        ans += c[i];
    cout << ans << endl;

    return 0;
}
