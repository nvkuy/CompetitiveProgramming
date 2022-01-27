#include <bits/stdc++.h>

using namespace std;

vector<int> a;
int n;

int cal(int si, int d, int l) {
    int co = 0, j;
    if (d == 0) {
        for (int i = 0; i < n; i++)
            if (a[i] == a[si])
                co++;
        return n - co;
    }
    j = 0;
    for (int i = si; i < n && i >= 0; i += l) {
        if (a[i] - a[si] == d * j)
            co++;
        j++;
    }
    j = 0;
    for (int i = si; i < n && i >= 0; i -= l) {
        if (a[si] - a[i] == d * j)
            co++;
        j++;
    }
    return n - co + 1;
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
        int co = n - 1;
        for (int i = 0; i < n; i++)
            co = min(co, cal(i, 0, 1));
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                co = min(co, cal(i, a[j] - a[i], j - i));
        cout << co << endl;
    }

    return 0;
}
