r = raw_input().split(' ')
n = int(r[0])
d = int(r[1])
while (n!=0 or d!=0):
	print n**d
	r = raw_input().split(' ')
	n = int(r[0])
	d = int(r[1])
