#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &s1, const string &s2) {
    return (s1 + s2) < (s2 + s1);
}

string a[50005];

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << endl;

    return 0;
}