# Enter your code here. Read input from STDIN. Print output to STDOUT
x=raw_input()
l=list(x)
for i in range(0,len(l)):
    if l[i]>='a' and l[i]<='z':
        l[i]=chr(ord(l[i])-32)
    elif l[i]>='A' and l[i]<='Z':
        l[i]=chr(ord(l[i])+32)
p="".join(l)
print p
