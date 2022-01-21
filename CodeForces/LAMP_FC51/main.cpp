#include <bits/stdc++.h>

using namespace std;
/*
unsigned int toggleBitsFromLToR(unsigned int n, unsigned int l, unsigned int r){
    int num = ((1 << r) - 1) ^ ((1 << (l - 1)) - 1);
    return (n ^ num);
}

string s;
void bin(unsigned n)
{
    if (n > 1)
        bin(n / 2);
    s = to_string(n % 2) + " " + s;
}
*/
bool ans[100001];

int main()
{
    /*
    int ans = 0, n, q, l, r;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        ans = toggleBitsFromLToR(ans, l, r);
    }
    bin(ans);
    cout << s;
    */
    int n, q, l, r;
    scanf("%d %d", &n, &q);
    memset(ans, false, sizeof(ans));
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        for (int j = l; j <= r; j++)
            ans[j] = !ans[j];
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);

    return 0;
}
