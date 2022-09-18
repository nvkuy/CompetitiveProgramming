#include <bits/stdc++.h>

using namespace std;

int n, k, maxD, curD, a[6000];

int main()
{

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    maxD = 0, curD = 0;
    for (int i = 0; i < (n - 1); i++) {
        for (int j = i + 1; j < n; j++) {
            curD = 0;
            for (int l = 0; l < k; l++) {
                if (j + l < n) {
                    if (a[i + l] != a[j + l]) {
                        curD++;
                    }
                }
            }
            maxD = max(maxD, curD);
        }
    }

    cout << maxD;

    return 0;
}
