#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

vector<int> a;
void printLV(int level) {
    for (int i = 1; i < level; i++)
        cout << a[i] << '.';
    cout << a[level] << '\n';
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        a.assign(n + 1, 0);
        int cl = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                cl++;
                a[cl] = 1;
                printLV(cl);
                continue;
            }
            if (a[cl] + 1 == arr[i]) {
                a[cl]++;
                printLV(cl);
            } else {
                while (a[cl] + 1 != arr[i])
                    cl--;
                a[cl] = arr[i];
                printLV(cl);
            }
        }
    }

    return 0;
}
