#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k, ja, ia, m;
    long long ma[101], mi[101][101], mt[101];
    cin >> k >> n >> ia >> ja >> m;
    for (int i = 0; i < n; i++)
        if (i == (ia - 1))
            ma[i] = 1;
        else
            ma[i] = 0;
    while (k--) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mi[i][j];
        memset(mt, 0, sizeof(mt));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mt[i] = ((mt[i] % m) + (((mi[j][i] % m) * (ma[j] % m)) % m)) % m;
            }
        }
        for (int i = 0; i < n; i++) {
            ma[i] = mt[i];
            //cout << ma[i] << " ";
        }
        //cout << endl;
    }
    cout << ma[ja - 1];

    return 0;
}
