#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int min_num = 1e9, pos = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > min_num) {
            pos = i;
            break;
        }
        min_num = min(min_num, a[i]);
    }
    cout << pos + 1 << endl;

    return 0;
}