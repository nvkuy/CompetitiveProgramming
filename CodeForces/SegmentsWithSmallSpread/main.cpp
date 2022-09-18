#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k, a[100001];
    multiset<long long> ms;
    cin >> n >> k;
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    long long j = 0, ans = 0;
    for (long long i = 0; i < n; i++) {
        ms.insert(a[i]);
        while ((*(ms.rbegin()) - *(ms.begin())) > k) {
            ms.erase(ms.find(a[j]));
            j++;
        }
        ans += (i - j + 1);
        //cout << ans << " " << i << " " << j << endl;
    }
    cout << ans;

    return 0;
}
