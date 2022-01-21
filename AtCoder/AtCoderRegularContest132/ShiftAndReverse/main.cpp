#include <bits/stdc++.h>

using namespace std;

int a[100001];

int main()
{
    int n, j, k, mm = 1e8;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    j = -1, k = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            j = i;
            k++;
        }
    }
    mm = min(j + 1, n - j + 1);
    if (k == n - 1)
        mm = min(mm, 1);
    cout << mm;

    return 0;
}
