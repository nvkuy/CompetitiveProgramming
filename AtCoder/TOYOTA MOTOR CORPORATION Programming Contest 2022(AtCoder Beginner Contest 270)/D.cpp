#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i];
    int ans = 0, turn = 1;
    while (a.size() > 0) {
        if (n < a.back()) {
            a.pop_back();
            continue;
        }
        n -= a.back();
        if (turn == 1)
            ans += a.back();
        turn = 1 - turn;
    }
    cout << ans << endl;

    return 0;
}