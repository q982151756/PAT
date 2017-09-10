#include<iostream>
using namespace std;
int main()
{
	long a1,b1,c1,a2,b2,c2,sum1,sum2,sum3;
	scanf("%ld.%ld.%ld %ld.%ld.%ld",&a1,&b1,&c1,&a2,&b2,&c2);
	sum3=c1+c2;
	sum2=b2+b1;
	sum1=a1+a2;
	int temp;
	temp=sum3/29;
	sum2+=temp;
	sum3%=29;
	temp=sum2/17;
	sum1+=temp;
	sum2%=17;
	printf("%ld.%ld.%ld",sum1,sum2,sum3);
	return 0;
}
