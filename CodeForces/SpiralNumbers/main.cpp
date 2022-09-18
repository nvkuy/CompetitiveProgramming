#include <bits/stdc++.h>

using namespace std;

/*
n = 4
1  2  3  4
12 13 14 5
11 16 15 6
10 9  8  7
n = 5
1  2  3  4  5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/

int ans[101][101], n;

int main()
{

    cin >> n;
    memset(ans, 0, sizeof(ans));
    int curN = 1, ln = n;
    for (int i = 0; i < (n / 2); i++) {
        for (int j = 0; j < ln; j++) {
            ans[i][i + j] = curN;
            curN++;
        }
        for (int j = 0; j < (ln - 1); j++) {
            ans[i + j + 1][i + ln - 1] = curN;
            curN++;
        }
        for (int j = 0; j < (ln - 1); j++) {
            ans[i + ln - 1][i + ln - 2 - j] = curN;
            curN++;
        }
        for (int j = 0; j < (ln - 2); j++) {
            ans[i + ln - 2 - j][i] = curN;
            curN++;
        }
        ln -= 2;
    }
    if (n % 2)
        ans[n / 2][n / 2] = curN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", ans[i][j]);
        }
        cout << endl;
    }

    return 0;
}
