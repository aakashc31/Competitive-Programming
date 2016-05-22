import sys;
def gcd(a,b):
	if(b==0):
		return a
	else:
		return gcd(b, a%b)

t = int(sys.stdin.readline().rstrip());
while(t):
	t-=1
	[a,b] = sys.stdin.readline().rstrip().split(' ');
	k = gcd(int(a),int(b))
	print k;