#include <iostream>
#include <cstdio>

#define f(i,n) for(lli i=0; i<n; i++)
#define getNum(n) scanf("%lld",&n)

typedef long long int lli;

struct date
{
		lli d,m,y;
};
	

lli getDays(lli m, bool isLeap)
{
	if(isLeap && m==2)
		return 29;
	else if(m==4 || m==6 || m==9 || m==11)
		return 30;
	else if (m==2)
		return 28;
	return 31;
}

bool check_leap(lli y)
{
	if(y%100==0)
	{
		if(y%400==0)
			return true;
		return false;
	}
	else if(y%4==0)
		return true;
	return false;
}

lli numDaysBetweenYears(lli l1, lli l2)
{
	lli s=0;
	while(l1<=l2)
	{
		if(check_leap(l1))
			s+=366;
		else
			s+=365;
		l1++;
	}
	return s;
}

lli from_beg(date d1)
{
	lli m=1, count =0;
	bool leap = check_leap(d1.y);
	while(m<d1.m)
	{
		count+=getDays(m,leap);
		m++;
	}
	count+=d1.d-1;
	return count;
}

lli till_end(date d1)
{
	lli count=0;
	lli m = d1.m+1;
	bool leap = check_leap(d1.y);
	while(m<=12)
	{
		count+=getDays(m,leap);
		m++;
	}
	count+= (getDays(d1.m,leap)-d1.d);
	return count;
}


lli difference(date d1, date d2)
{
	lli total = numDaysBetweenYears(d1.y,d2.y);
	return 0;
}

// day on 1/1/y
lli day(lli y)
{
	lli k = (y-1900) + ((y-1900-1)/4) - ((y-1)/100 - 1900/100 - (y-1)/400 + 1900/400);
	return k%7;
}

int modtemp(int t)
{
	if(t<0)
		return t+7;
	else
		return t%7;
}
lli numSundayOnFirstInYear(lli y)
{
	lli k = day(y);
	lli c= (k==6)?1:0;
	lli numD=31;
	f(i,11)
	{
		lli m=i+2;
		if(modtemp((numD+1)%7+k-1)==6)
			c++;
		numD += getDays(m,check_leap(y));
	}
	return c;
}

lli numSundayOnFirstInYearFrom(lli y, lli l)
{
	lli k = day(y);
	lli c= (k==6 && l<=1)?1:0;
	lli numD=31;
	f(i,11)
	{
		lli m=i+2;
		if(modtemp((numD+1)%7+k-1)==6 && l<=m)
			c++;
		numD += getDays(m,check_leap(y));
	}
	return c;
}

lli numSundayOnFirstInYearTill(lli y, lli l)
{
	lli k = day(y);
	lli c= (k==6 && l<=1)?1:0;
	lli numD=31;
	f(i,11)
	{
		lli m=i+2;
		if(modtemp((numD+1)%7+k-1)==6 && l>=m)
			c++;
		numD += getDays(m,check_leap(y));
	}
	return c;
}

lli numSundayOnFirstInYearFromTo(lli y, lli m1, lli m2)
{
	return numSundayOnFirstInYear(y)-numSundayOnFirstInYearTill(y,m1-1) - numSundayOnFirstInYearFrom(y,m2+1);
}

int main()
{
	lli t,d1,m1,y1,d2,m2,y2;
	getNum(t);
	while(t--)
	{
		getNum(y1);getNum(m1),getNum(d1);getNum(y2),getNum(m2),getNum(d2);
		lli s=0;
		if(d1>1)
		{
			s+=numSundayOnFirstInYearFrom(y1,m1+1);
		}
		else
		{
			s+=numSundayOnFirstInYearFrom(y1,m1);
		}
		s+=numSundayOnFirstInYearTill(y2,m2);
		for(lli y=y1+1;y<y2;y++)
			s+=numSundayOnFirstInYear(y);
		if(y1==y2)
		{
			s=0;
			if(d1>1)
			{
				s+=numSundayOnFirstInYearFromTo(y1,m1+1,m2);
			}
			else
			{
				s+=numSundayOnFirstInYearFromTo(y1,m1,m2);
			}
		}
		printf("%lld\n",s );
	}
	return 0;
}