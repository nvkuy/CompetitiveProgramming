#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

void build_tree(vector<long long> &b, vector<long long> &seg_tree, long long l, long long r, long long vertex)
{
    if (l >= b.size())
        return;
	if (l == r) {
		seg_tree[vertex] = b[l];
		return;
	}
	long long mid = (l + r) / 2LL;
	build_tree(b, seg_tree, l, mid, 2LL * vertex);
	build_tree(b, seg_tree, mid + 1, r, 2LL * vertex + 1);

	seg_tree[vertex] = __gcd(seg_tree[2LL * vertex], seg_tree[2LL * vertex + 1]);
}

long long range_gcd(vector<long long> &seg_tree, long long v, long long tl, long long tr, long long l, long long r)
{
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return seg_tree[v];
	long long tm = (tl + tr) / 2LL;
	return __gcd(range_gcd(seg_tree, 2LL * v, tl, tm, l, min(tm, r)), range_gcd(seg_tree, 2LL * v + 1, tm + 1, tr, max(tm + 1, l), r));
}

long long maxSubarrayLen(vector<long long> &arr) {
    long long n = arr.size();
    vector<long long> seg_tree(4LL * n + 1, 0LL);
	build_tree(arr, seg_tree, 0LL, n - 1, 1);
	long long maxLen = 0;
	long long l = 0, r = 0;
	while (r < n && l < n) {
		if (range_gcd(seg_tree, 1, 0, n - 1, l, r) == 1)
			l++;
		maxLen = max(maxLen, r - l + 1);
		r++;
	}

	return maxLen;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    long long n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n - 1; i++)
            arr[i] = llabs(arr[i + 1] - arr[i]);
        arr.pop_back();
        cout << maxSubarrayLen(arr) + 1 << endl;
    }

	return 0;
}
