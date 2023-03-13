#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> e(n);
    int fb_first = -1, fb_last = -1, sb_first = -1, sb_last = -1;
    for (int i = 0; i < n; i++) {
        cin >> e[i];
        e[i]--;
        if (s[i] == 'G') {
            fb_last = i;
            if (fb_first == -1)
                fb_first = i;
        } else {
            sb_last = i;
            if (sb_first == -1)
                sb_first = i;
        }
    }
    if (fb_first > sb_first) {
        swap(fb_first, sb_first);
        swap(fb_last, sb_last);
    }
    int ans = 0;
    if (e[fb_first] >= min(fb_last, sb_first))
        ans++;
    for (int i = fb_first + 1; i < sb_first; i++)
        ans += (e[i] >= sb_first);
    cout << ans << endl;

    return 0;
}