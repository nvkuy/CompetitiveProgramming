#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, MAXN = 1e6;
    cin >> n;
    vector<int> cnt(MAXN + 1, 0);
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        cnt[ai]++;
    }
    int ans = 1;
    for (int i = 1; i <= MAXN; i++) {
        int num_cnt = 0;
        for (int j = 1; i * j <= MAXN; j++) {
            if (num_cnt > 1) break;
            num_cnt += cnt[i * j];
        }
        if (num_cnt > 1) ans = i;
    }
    cout << ans << endl;

    return 0;

}