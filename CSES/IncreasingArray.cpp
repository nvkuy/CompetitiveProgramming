#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;   
    cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long c = 0LL;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            c += (a[i - 1] - a[i]);
            a[i] = a[i - 1];
        }
    }
    cout << c;

    return 0;
}
