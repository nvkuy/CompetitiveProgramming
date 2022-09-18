#include <bits/stdc++.h>

using namespace std;

long long cal(long long n) {
    long long ans = 0;
    for (int i = 1; pow(5, i) <= n; i++)
        ans += (i * ((long long)(n / pow(5, i)) - (long long)((long long)(n / pow(5, i)) / 5)));
    return ans;
}

int main()
{

    int t;
    long long n;
    cin >> t;
    while (t > 0) {
        t--;
        cin >> n;
        cout << cal(n) << endl;
    }

    return 0;
}
