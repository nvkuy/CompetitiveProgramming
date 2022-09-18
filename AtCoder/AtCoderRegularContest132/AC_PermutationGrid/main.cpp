#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> b;
vector<char> rs;

int main()
{
    int n, bi;
    scanf("%d", &n);
    a.resize(n); b.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    int q, r, c;
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &r, &c);
        if (b[c - 1] >= n - a[r - 1] + 1)
            rs.push_back('#');
        else
            rs.push_back('.');
    }
    for (int i = 0; i < rs.size(); i++)
        printf("%c", rs[i]);

    return 0;
}
