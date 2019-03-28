//sum of two fraction numbers...
#include<stdio.h>
struct fraction
{
	int numerator;
	int denominator;
};
void inputfraction(struct fraction* fr)
{
	int i=0;
	for(i=0;i<2;++i)
	{
		scanf("%d%d",&fr[i].numerator,&fr[i].denominator);
	}
}
int getgcd(int a,int b)
{
	while(a!=b)
	{	if(a>b)
			a-=b;
		else
			b-=a;
	}
	return a;
}
struct fraction addfraction(struct fraction* fract)
{
	int n,d,gcd;
	struct fraction sum;
	d=fract[0].denominator*fract[1].denominator;
	n=(fract[0].numerator*fract[1].denominator)+(fract[1].numerator*fract[0].denominator);
	gcd=getgcd(n,d);
	n/=gcd;
	d/=gcd;
	sum.numerator=n;
	sum.denominator=d;
	return sum;
}
int main()
{
	struct fraction frac[2],result;
	inputfraction(frac);
	result=addfraction(frac);
	printf("%d %d",result.numerator,result.denominator);
	return 0;	
}
