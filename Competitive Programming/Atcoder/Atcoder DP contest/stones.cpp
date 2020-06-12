#include<stdio.h>

long long int max(long long int a,long long int b)
{
	if(a>b) return a;
	return b;
}

long long int min(long long int a,long long int b)
{
	if(a<b) return a;
	return b;
}
long long int dp[3002][3002];
long long int D(long long int d[], int l,int r)
{
  if( dp[l][r] > 0 )
    return dp[l][r];
	if(l<r)	dp[l][r] = max(d[l]+min(D(d,l+1,r-1),D(d,l+2,r)),d[r]+min(D(d,l,r-2),D(d,l+1,r-1)));
	else if(l==r) dp[l][r] = d[l];
	else
     dp[l][r] = 0;
  return dp[l][r];
}

long long int d[3002];

int main()
{
	long long int n;
	long long int sum=0;
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&d[i]);
		sum+=d[i];
	}

	// if(D(d,0,n-1)<sum-D(d,0,n-1)) printf("2\n%lld\n",sum-D(d,0,n-1));
	printf("%lld\n",2*D(d,0,n-1)-sum);
	return 0;
}

