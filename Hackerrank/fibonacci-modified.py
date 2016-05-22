
ar = 20*[0]

def init(a,b):
	ar[0] = a
	ar[1] = b
	i = 2
	while i<20:
		ar[i] = ar[i-1]*ar[i-1] + ar[i-2]
		i+=1

l = raw_input()
l = l.split()
a = int(l[0])
b = int(l[1])
n = int(l[2])
init(a,b)
print ar[n-1]