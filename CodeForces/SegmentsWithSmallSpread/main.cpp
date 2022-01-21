#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k, a[100001];
    multiset<long long> ms;
    cin >> n >> k;
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    long long j = 0, ans = 0, cm = -1;
    for (long long i = 0; i < n; i++) {
        if (cm - a[i] > k) {
            cm = a[i];
            ms.clear();
            j = i + 1;
        }
        ms.insert(a[i]);
        if (a[i] > cm)
            cm = a[i];
        while ((cm - *(ms.begin())) > k) {
            if (*(ms.begin()) != a[j]) {
                ms.erase(ms.find(a[j]));
                j++;
                continue;
            }
            ms.erase(ms.begin());
            j++;
        }
        ans += (i - j + 1);
        //cout << ans << " " << i << " " << j << endl;
    }
    cout << ans;

    return 0;
}
