# Multiples of 3 and 5
n = int(raw_input())
for i in range(n):
    k = int(raw_input())
    by3 = (k-1) / 3
    by5 = (k-1) / 5
    by15 = (k-1) / 15
    ans = 3 * by3 * (by3+1) / 2 + 5 * by5 * (by5+1) / 2 - 15 * by15 * (by15+1) / 2
    print ans
