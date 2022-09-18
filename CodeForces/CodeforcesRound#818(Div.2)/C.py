t = int(input())

for _ in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	isOk = True
	needInc = False
	for i in range(n):
		if a[i] > b[i]:
			isOk = False
			break
		if a[i] < b[i] or needInc:
			needInc = False
			next = (i + 1) % n
			a[i] = b[i]
			if a[next] < b[i] - 1:
				a[next] = b[i] - 1
				needInc = True
			if (a[next] > b[next]):
				isOk = False
				break
	print("YES" if isOk else "NO")
