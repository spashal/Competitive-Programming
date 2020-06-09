#include<stdio.h>

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);      
} 

int main()
{
	int a,b;
    scanf("%d%d",&a,&b);
  	int t=gcd(a,b);
  	int u=(a*b)/t;
  	printf("%d\n",u);
  	return 0;
}