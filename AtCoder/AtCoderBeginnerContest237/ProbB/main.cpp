#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;

int main()
{
    int h, w;
    cin >> h >> w;
    a.resize(h);
    for (int i = 0; i < h; i++) {
        a[i].resize(w);
        for (int j = 0; j < w; j++)
            cin >> a[i][j];
    }
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++)
            cout << a[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
