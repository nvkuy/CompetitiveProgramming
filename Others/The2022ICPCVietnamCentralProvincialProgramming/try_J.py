n, m, a, b = list(map(int, input().split()))


hanga = a//m
if a % m == 0:
    hanga -= 1
hangb = b//m
if b % m == 0:
    hangb -= 1


res = 3
if hanga == hangb:
    res = 1
elif a % m == 1 and b % m == 0:
    res = 1
elif a % m == 1 and b == n:
    res = 1


elif hangb-hanga == 1:
    res = 2
elif b == n:
    res = 2
elif a % m-b % m == 1:
    res = 2
elif a % m == 0 and b % m == m-1:
    res = 2
elif a % m == 1 and b % m != 0:
    res = 2
elif a % m != 1 and b % m == 0:
    res = 2

else:
    res = 3

print(res)