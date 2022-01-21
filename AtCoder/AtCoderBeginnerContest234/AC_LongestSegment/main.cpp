#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    double x[101], y[101], md, cd;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    md = -1e-7;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            cd = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            if (cd > md)
                md = cd;
        }
    }
    printf("%lf", md);

    return 0;
}
