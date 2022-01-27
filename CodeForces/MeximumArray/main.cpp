#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> a(n), dd(n + 1), ans;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int j = 0, k, i, km = n, im;
        while (j < n) {
            fill(dd.begin(), dd.begin() + km + 1, 0);
            k = 0, i;
            for (i = j; i < n; i++) {
                dd[a[i]]++;
                if (a[i] == k) {
                    while (dd[k] > 0)
                        k++;
                    if (k >= km)
                        break;
                }
            }
            im = i;
            for (i = min(im, n - 1); i >= j; i--) {
                dd[a[i]]--;
                if (dd[a[i]] <= 0 && a[i] < k)
                    break;
            }
            if (j == i + 1 || k <= 0) {
                while (j < n) {
                    ans.push_back(k);
                    j++;
                }
                break;
            }
            j = i + 1;
            km = k;
            ans.push_back(k);
        }
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++)
            printf("%d ", ans[i]);
        printf("\n");
    }

    return 0;
}
