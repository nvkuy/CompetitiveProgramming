n, k = map(int, input().split(' '))
a = list(map(int, input().split(' ')))

ans = 0
for mask in range(1, 1 << k):
    mask_lcm = 1
    bit_cnt = 0
    for i in range(0, k):
        if ((1 << i) & mask) > 0:
            mask_lcm = min(mask_lcm * a[i], n + 1)
            bit_cnt += 1
    if (bit_cnt & 1) == 0:
        mask_lcm *= -1
    ans += int(n / mask_lcm)

print(ans)
    
