#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a[100001], b[100001];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int j = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        while (b[i] > a[j]) {
            if (n == j)
                break;
            j++;
        }
        printf("%d ", j);
    }

    return 0;
}
