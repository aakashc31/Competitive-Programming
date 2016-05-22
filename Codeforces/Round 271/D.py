ar = 100001*[0]
def get(n,k):
	d = n/k;
	ans = 1 + d*(n+1) - k*((d*(d+1))/2);
	return ans;	

def init(k):
	ar[0] = 0;
	i=1
	while i<=100000:
		ar[i] = (ar[i-1] + get(i,k));
		i+=1


def main():
	modulo = 10**9+7
	tq = raw_input().split(' ');
	t = int(tq[0])
	k = int(tq[1])
	init(k)
	i=0;
	while i<t:
		tq = raw_input().split(' ');
		a = int(tq[0])
		b = int(tq[1])
		print (ar[b]-ar[a-1])%modulo
		i+=1
main()