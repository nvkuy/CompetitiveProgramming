#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 5;

std::vector <int> primes;
int fac[MAX_N], phi[MAX_N];

void sieve () {
    primes.clear();
    for (int i = 0; i < MAX_N; i++) fac[i] = i;
	for (int i = 2; i < MAX_N; i++) {
		if (fac[i] == i) primes.push_back (i);
		for (int j = 0; j < primes.size () && i * primes[j] < MAX_N; j++) {
			fac[i * primes[j]] = primes[j];
			if (i % primes[j] == 0) break;
		}
	}
}

void pre_phi() {
    primes.clear();
	for (int i = 1; i < MAX_N; i++) { phi[i] = i; }
	for (int i = 2; i < MAX_N; i++) {
		if (phi[i] == i) {
			primes.push_back(i);
            phi[i] = i - 1;
		}
        for (int j = 0; j < primes.size () && i * primes[j] < MAX_N; j++) {
            if (i % primes[j] == 0) {
                phi[i * primes[j]] = primes[j] * phi[i];
                break;
            }
            phi[i * primes[j]] = (primes[j] - 1) * phi[i];
        }
	}
}
