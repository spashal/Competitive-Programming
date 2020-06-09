#include<bits/stdc++.h>
using namespace std;

int main()
{
	int
	cin >> n;
	for( int i = 0 ; i < n ; i++ )
		cin >> a[i];
	for( int i = 0 ; i < n ; i++ ){
		for( int j = k ; j < n ; j++ ){
			if( k - j == s - a[j] && b[j] == 0 ){
				ans += a[j];
				k = j;
				s = a[j];
				b[j] = -1;
			}
			maxa = max(maxa, ans);
			ans = 0;
			k = -1;
		}
	}
}