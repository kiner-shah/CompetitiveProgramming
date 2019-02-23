# Factorial digit sum
def fact(n):
    pr=1
    for i in range(1,n+1):
        pr=pr*i
    return pr
def calc_sum(a):
    sum=0
    while(a>0):
        sum=sum+(a%10)
        a=a/10
    return sum
t=int(raw_input())
for i in range(t):
    n=int(raw_input())
    ans=fact(n)
    #print ans
    print calc_sum(ans)
