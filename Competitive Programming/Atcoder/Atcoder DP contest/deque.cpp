#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define ari for( int i = 1 ; i <= n ; i++ ) cin >> a[i];

int main(){
	cin >> n;
	ari;
	for( int i = n ; i > 0 ; i-- )
		for( int j = n ; j >= i ; j-- )
			dp[i][j] = min( dp[i+1][j] + a[i+1], dp[i][j] + a[j])
	return(0);
}