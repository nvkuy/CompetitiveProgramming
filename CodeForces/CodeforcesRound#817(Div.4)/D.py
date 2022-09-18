def getVal(n, pos, dir):
	if dir == "L":
		return pos
	return n - pos - 1

t = int(input())

for _ in range(t):
	n = int(input())
	st = input()
	s = list(st)
	curVal = 0
	for i in range(n):
		curVal += getVal(n, i, s[i])
	l = 0
	r = n - 1
	for i in range(n):
		while l < n and s[l] == "R":
			l += 1
		while r >= 0 and s[r] == "L":
			r -= 1
		dt1 = dt2 = 0
		if l < n / 2:
			dt1 = getVal(n, l, "R") - getVal(n, l, s[l])
		if r >= n / 2:
			dt2 = getVal(n, r, "L") - getVal(n, r, s[r])
		if dt1 > dt2:
			s[l] = "R"
			curVal += dt1
			l += 1
		else:
			s[r] = "L"
			curVal += dt2
			r -= 1
		print(curVal, end=" ", flush=False)
	print(flush=True)
