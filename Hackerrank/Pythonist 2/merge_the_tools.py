# Enter your code here. Read input from STDIN. Print output to STDOUT
x=raw_input()
n=int(raw_input())
i=0
d={}
while i<len(x)-n+1:
    temp=x[i:i+n]
    cont=[]
    ans=""
    for j in temp:
        if j in cont:
            continue
        else:
            ans=ans+str(j)
            cont.append(j)
    print ans
    i=i+n
