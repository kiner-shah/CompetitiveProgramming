def polynomial_and_its_roots():
	# Enter your code here. Read input from STDIN. Print output to STDOUT
	n=int(raw_input())
	x=raw_input()
	l=x.split()
	sum=(int(l[len(l)-2])/int(l[len(l)-1]))*-1
	pr=((-1)**(len(l)-1))*int(l[0])/int(l[len(l)-1])
	print sum,pr

# polynomial_and_its_roots()
