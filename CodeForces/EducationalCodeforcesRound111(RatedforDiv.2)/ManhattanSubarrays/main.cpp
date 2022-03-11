#include <bits/stdc++.h>

using namespace std;

map<int, deque<int>> mx;
map<int, deque<int>>::iterator it;
vector<int> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, nj;
    long long ans;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        mx.clear();
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int j = 0;
        ans = 0LL;
        for (int i = 0; i < n; i++) {
            it = mx.find(a[i]);
            if ((it == mx.end()) || ((*it).second.back() == j)) {
                ans += (i - j + 1);
                //cout << j << '|' << i << endl;
                if ((*it).second.size() == 1) {
                    (*it).second.pop_front();
                    j++;
                }
                mx[a[i]].push_back(i);
                continue;
            }
            nj = (*it).second.back();
            for (j; j < nj; j++)
                mx[a[j]].pop_front();
            ans += (i - j + 1);
            //cout << j << '|' << i << endl;
            (*it).second.pop_front();
            j++;
            (*it).second.push_back(i);
        }
        cout << ans << endl;
    }

    return 0;
}
