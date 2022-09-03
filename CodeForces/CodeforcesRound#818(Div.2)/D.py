n, k = map(int, input().split())
k = min(k, n)
mod = 10 ** 9 + 7

fac = [1]
for i in range(1, n + 1):
	fac.append((fac[i - 1] * i) % mod)

def modInv(a):
	return pow(a, mod - 2, mod)

def comb(nn, kk):
	return (fac[nn] * modInv(fac[kk] * fac[nn - kk])) % mod

ans = 0
for i in range(k + 1):
	ans += comb(n, i)
	ans %= mod

print(ans) 