#include <bits/stdc++.h>

using namespace std;

int n, q, qt, a[10000];

int cal(int qi) {
    int ml = 0, cl = 0;
    a[n] = qi + 1;
    for (int i = 0; i <= n; i++) {
        if (a[i] <= qi)
            cl++;
        else {
            if (ml < cl)
                ml = cl;
            cl = 0;
        }
    }
    return ml;
}

int main()
{

    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < q; i++) {
        cin >> qt;
        cout << cal(qt) << "\n";
    }

    return 0;
}
