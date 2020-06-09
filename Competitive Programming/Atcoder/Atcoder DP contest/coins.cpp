#include <bits/stdc++.h>
using namespace std;
typedef double ff;
#define ari for( int i = 1 ; i <= n ; i++ ) cin >> p[i];
int n;
ff p[3002], dp[3002];

int main(){
	cin >> n;
	ari;
	dp[0] = 1.000;
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = i ; j > 0 ; j-- )
			dp[j] = dp[j] * ( 1 - p[i]) + dp[ j - 1 ] * p[i];
		dp[0] *= ( 1 - p[i]);
	}
	for( int i = n/2 + 1 ; i <= n ; i++ )
		dp[ n + 1 ] += dp[i];
	cout << setprecision(11) << dp[ n + 1 ] << endl;
	return(0);
}