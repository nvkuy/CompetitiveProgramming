#include <bits/stdc++.h>
#define long long long
using namespace std;
int n, t;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        priority_queue<long, vector<long>, greater<long> > heap;
        int v;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &v);
            heap.push(v);
        }
        long res = 0;
        while (heap.size() > 1) {
            int a = heap.top(); heap.pop();
            int b = heap.top(); heap.pop();
            res += a + b;
            heap.push(a + b);
        }
        printf("%lld\n", res);
    }
    return 0;
}
