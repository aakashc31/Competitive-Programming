long long int ncr(long n, long r)
{
	if(r > n-r)
		r = n-r;
	if(r==0)
		return 1;
	else if(r==1)
		return n;
	else if(n==r)
		return 1;
	long long s = 1.0;
	int aa = n-r+1;
	f(i,r)
	{
		s = s*(aa+i)/(i+1);
	}
	// long long int a =s;
	return s;
}