#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
 }

int main()
{
	int i;
	long long int x;
	cin>>x;
	int r=sqrt(x);
	if(x/r==r && r!=1) r--;
	for(i=r;i>=1;i--)
	{
		if(x%i==0) 
		{
			if(1==gcd(i,x/i))
			break;
		}
	}
	long long int e=x/i;
	cout<<i<<" "<<e<<'\n';
	return(0);
}