#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>s[i];
	for(i=1; i<n; i++)
    {
        for(j=1; j<n; j++)
        {
            if(strcmp(s[j-1], s[j])>0)
            {
	            strcpy(t, s[j-1]);
	            strcpy(s[j-1], s[j]);
	            strcpy(s[j], t);
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
    	if(s[i]==s[i+1]) t++;
    	else if(t!=0) ans+=t*
    }
}