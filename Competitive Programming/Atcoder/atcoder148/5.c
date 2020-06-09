#include<stdio.h>

int main()
{
  long long int n;
  scanf("%lld",&n);
  if(n%2==1) printf("0\n");
  else
  {
	long long int t=n/10,u=10;
    for(int i=1;i<25;i++)
    {
      u=u*5;
      t+=n/u;
    }
    printf("%lld\n",t);
  }
  return 0;
}
  
