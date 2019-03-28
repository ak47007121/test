#include<stdio.h>
#include<stdlib.h>
struct fraction
{
	int numerator;
	int denominator;
};
void inputfraction(struct fraction* fr, int n)
{
	int i;
	for(i=0;i<n;++i)
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
struct fraction addfraction(struct fraction* fract,int n)
{
	int i,gcd;
	struct fraction sum;
	sum.denominator=1;
	sum.numerator=0;
	for(i=0;i<n;++i)
	{
 		sum.denominator*=fract[i].denominator;
	}
	for(i=0;i<n;++i)
	{
		sum.numerator+=(fract[i].numerator*(sum.denominator/fract[i].denominator));
	}
	gcd=getgcd(sum.numerator,sum.denominator);
	sum.numerator/=gcd;
	sum.denominator/=gcd;
	return sum;
}
int main()
{
	struct fraction* frac,result;
	int n;
	scanf("%d",&n);
	frac=malloc(n*sizeof(struct fraction));
	inputfraction(frac,n);
	result=addfraction(frac,n);
	printf("%d %d",result.numerator,result.denominator);
	return 0;	
}
