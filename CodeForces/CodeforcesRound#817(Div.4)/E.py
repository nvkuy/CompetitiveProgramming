max_cor = 1001
f = [[0 for _ in range(max_cor)] for _ in range(max_cor)]
c = [[0 for _ in range(max_cor)] for _ in range(max_cor)]

t = int(input())
for _ in range(t):
	for i in range(max_cor):
		for j in range(max_cor):
			f[i][j] = c[i][j] = 0
	n, q = map(int, input().split())
	for _ in range(n):
		w, h = map(int, input().split())
		c[w][h] += 1
	for i in range(1, max_cor):
		for j in range(1, max_cor):
			f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + i * j * c[i][j]
	for _ in range(q):
		hs, ws, hb, wb = map(int, input().split())
		print(f[hb - 1][wb - 1] - f[hb - 1][ws] - f[hs][wb - 1] + f[hs][ws])