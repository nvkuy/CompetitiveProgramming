#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, m, a[100001], b[100001];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    a[n] = b[m] = 1e9 + 7;
    int i = 0, j = 0;
    while (i + j < n + m) {
        if (a[i] < b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    return 0;
}
