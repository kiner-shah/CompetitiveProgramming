# Names scores
def find_score(a):
    sum=0
    for i in a:
        sum=sum+ord(i)-ord('A')+1
    return sum
n=int(raw_input())
l=[]
#print ord('P')
for i in range(n):
    x=raw_input()
    l.append(x)
l.sort()
q=int(raw_input())
for i in range(q):
    x=raw_input()
    for y in range(len(l)):
        if l[y]==x:
            ans=find_score(l[y])
            print ans*(y+1)
            break
