#include <bits/stdc++.h>

using namespace std;

int n, m, tmp, td[300][300], tp[300][300], maxE;

bool checkSqu(int x1, int x2, int y) {

    int edge = x2 - x1;
    if (y + edge > m)
        return false;

    if (tp[x2][y] - edge != tp[x1][y]) { //check lien tuc ngang 1
        return false;
    } else {
        int y2 = y + edge;
        if (td[x2][y2] - edge != td[x2][y]) { //check lien tuc doc 2
            return false;
        } else {
            int y1 = y2;
            if (tp[x2][y2] - edge != tp[x1][y1]) { //check lien tuc ngang 2
                return false;
            } else {
                if (td[x1][y1] - edge != td[x1][y]) //check lien tuc doc 1
                    return false;
                else
                    return true;
            }
        }
    }

    return true;
}

int main()
{

    cin >> m >> n;
    memset(td, 0, sizeof(td));
    memset(tp, 0, sizeof(tp));
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            if (tmp == 0) {
                td[i][j] = 0;
                tp[i][j] = 0;
            } else {
                td[i][j] = td[i][j - 1] + 1;
                tp[i][j] = tp[i - 1][j] + 1;
            }
        }
    }
    /*for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            cout << tp[i][j] << "|" << td[i][j] << " ";
        }
        cout << endl;
    }*/
    maxE = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= j; k++) {
                if (checkSqu(k, j, i))
                    //cout << k << " " << j << " " << i << "\n";
                    maxE = max(maxE, j - k + 1);
                    break;
            }
        }
    }
    cout << maxE * maxE;

    return 0;
}
