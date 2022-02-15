#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, ai, mu;
    cin >> t;
    while (t--) {
        cin >> n;
        stack<int> co;
        mu = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ai;
            if (ai > mu) {
                co.push(ai);
                mu = ai;
            } else {
                while (!co.empty()) {
                    if (co.top() > ai)
                        co.pop();
                    else
                        break;
                }
                co.push(mu);
            }
        }
        cout << co.size() << endl;
    }

    return 0;
}
