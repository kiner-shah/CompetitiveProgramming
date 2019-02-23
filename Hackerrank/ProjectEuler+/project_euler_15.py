# Lattice paths
def fact(n):
    if n==0 or n==1:
        return 1
    else:
        return n*fact(n-1)
t=int(raw_input())
for i in range(t):
    x=raw_input()
    nm=x.split()
    ans=fact(int(nm[0])+int(nm[1]))/(fact(int(nm[0]))*fact(int(nm[1])))
    print ans%1000000007
