#include <bits/stdc++.h>

using namespace std;

int check(long long n, int a) {
    double x1 = (-1 + sqrt(1 + (4 * n / a))) / 2;
    double x2 = (-1 - sqrt(1 + (4 * n / a))) / 2;
    if ((double)(((int)x1) - x1) < 0)
        return -100;
    if ((double)(((int)x2) - x2) < 0)
        return -100;
    return (int)(max(x1, x2));
}

int main()
{

    int t, j;
    bool hld;
    long long n;
    vector<int> ans;
    scanf("%d", &t);
    while (t--) {
        hld = false;
        scanf("%lld", &n);
        for (int i = 1; (i * i * i) <= n; i++) {
            if (n % i == 0) {
                if (n % (i + 1) == 0) {
                    //ans.push_back(i);
                    printf("%d ", i);
                    hld = true;
                }
                j = check(n, i);
                if (j > 0)
                    ans.push_back(j);
            }
        }
        if (ans.size() + hld == 0) {
            printf("-1\n");
            continue;
        }
        if (ans.size() + hld == hld) {
            printf("\n");
            continue;
        }
        //sort(ans.begin(), ans.end());
        for (int i = ans.size() - 1; i >= 0; i--)
            printf("%d ", ans[i]);
        printf("\n");
        ans.clear();
    }

    return 0;
}
