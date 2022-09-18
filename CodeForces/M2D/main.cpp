#include <bits/stdc++.h>

using namespace std;

int maxn = 2000001;
bool nt[2000001];
vector<int> nts;

int main()
{

    nt[1] = false;
    for (int i = 2; i <= maxn; i++)
        nt[i] = true;
    for (int i = 2; i * i <= maxn; i++) {
        if (nt[i]) {
            for (int j = i * i; j <= maxn; j += i)
                nt[j] = false;
        }
    }

    for (int i = 2; i <= maxn; i++) {
        if (nt[i])
            nts.push_back(i);
    }

    int t, n, i, j;
    cin >> t;
    while (t > 0) {
        t--;
        cin >> n;
        i = lower_bound(nts.begin(), nts.end(), n) - nts.begin();
        j = i - 1;
        i = nts[i]; j = nts[j];
        if (abs(n - i) == abs(n - j))
            cout << j;
        else
            cout << (abs(n - i) < abs(n - j) ? i : j);
        cout << "\n";
    }

    return 0;
}
