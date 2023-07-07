#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
	int size;
	vector<int> tree;
	SegmentTree() : size(1 << 20) { tree.assign(size * 2, 0); }

	void update(int x, int value) {
		x += size;
		tree[x] += value;
		while (x > 0) {
			x /= 2;
			tree[x] = tree[2 * x] + tree[2 * x + 1];
		}
	}

	int query(SegmentTree &other) {
		int west_size, east_size, other_west_size, other_east_size;
		west_size = east_size = other_west_size = other_east_size = 0;
		int mid = 1;
		while (mid < size) {
			int l = mid * 2;
			int r = mid * 2 + 1;
			if (max(west_size + tree[l], other_west_size + other.tree[l]) <
			    max(east_size + tree[r], other_east_size + other.tree[r])) {
				mid = r;
				west_size += tree[l];
				other_west_size += other.tree[l];
			} else {
				mid = l;
				east_size += tree[r];
				other_east_size += other.tree[r];
			}
		}

		if (max(west_size + tree[mid], other_west_size + other.tree[mid]) <
		    max(east_size + tree[mid], other_east_size + other.tree[mid])) {
			west_size += tree[mid];
			other_west_size += other.tree[mid];
		} else {
			east_size += tree[mid];
			other_east_size += other.tree[mid];
		}

		return max(max(west_size, east_size),
		           max(other_west_size, other_east_size));
	}
};

int main() {
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);

	int N;
	cin >> N;
	vector<pair<int, int>> cows(N);
	for (pair<int, int> &c : cows) { cin >> c.first >> c.second; }

	sort(cows.begin(), cows.end(),
	     [&](const pair<int, int> &c1, const pair<int, int> &c2) {
		     return make_pair(c1.second, c1.first) <
		            make_pair(c2.second, c2.first);
	     });

	SegmentTree north;
	SegmentTree south;

	for (int i = 0; i < N; i++) { north.update(cows[i].first, 1); }

	int M = N;

	for (int i = 0; i < N;) {
		int j = i;
		while (j < N && cows[i].second == cows[j].second) {
			north.update(cows[j].first, -1);
			south.update(cows[j].first, 1);
			j++;
		}

		M = min(M, north.query(south));
		i = j;
	}

	cout << M << endl;
}