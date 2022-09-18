#include <bits/stdc++.h>

using namespace std;

vector<int> a;
int x, y, n;

int cal(int div, int b) {
    if (div == 3) {
        int i = 1, rm = n - b;
        while (i < rm)
            i *= 2;
        return i - rm;
    } else if (div == 2) {

    } else {

    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end(), greater<int>());
    }

    return 0;
}
