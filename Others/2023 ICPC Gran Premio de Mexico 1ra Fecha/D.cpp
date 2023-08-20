#include<bits/stdc++.h>
using namespace std;

void solve(){
	long long n, q;
	cin >> n >> q;
	vector<long long> a;
	for (int i = 0; i < n; i++){
		long long x; cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	while (q--){
		int o; cin >> o;
		if (o == 1){
			int k; cin >> k;
			if (k < a[0]) continue;
			else if (k > a.back()){
				a.push_back(k);
				continue;
			}
			else {
				vector<long long>::iterator it;
				it = upper_bound(a.begin(), a.end(), k);
                it--;
                if (*it == k) continue;
                it++;
                *it = k;
			}
		} else {
			int A, B; cin >> A >> B;
			vector<long long>::iterator l, r;
			l = lower_bound(a.begin(), a.end(), A);
			r = upper_bound(a.begin(), a.end(), B);
			cout << r-l << endl;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
		cin.tie(0);
	solve();
	return 0;
}