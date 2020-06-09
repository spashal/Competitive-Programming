#include<stdio.h>
 
long long int floorSqrt(int x)  
{
    if (x == 0 || x == 1)  
       return x; 
  
    long long int start = 1, end = x, ans;    
    while (start <= end)  
    {         
        long long int mid = (start + end) / 2; 
  
        if (mid*mid == x) 
            return mid; 
  
        if (mid*mid < x)  
        { 
            start = mid + 1; 
            ans = mid; 
        }  
        else end = mid-1;         
    } 
    return ans; 
}

int main()
{
	int j,t,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		long long int s=floorSqrt(n);
		printf("%lld=sqrt\n",s);
		if(n==1) printf("2\n");
		else if(n==2 || n==3) printf("3\n");
		else if(s==n/s) printf("%lld\n",2*s);
		else printf("%lld\n",2*s+1);
		for(int j=0;j<=s;j++) printf("%d ",j);
		if(s!=n/j) printf("%d ",n/j);
		for(int j=s-1;j>0;j--) printf("%d ",n/j);
		printf("\n");
	}
	return 0;
}