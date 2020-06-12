#include <bits/stdc++.h>
using namespace std;
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
int n, K, dp[100001][101], a[101], mod = 1000000007;

// int DP( int k, int j){
// 	cout << k << " " << j << endl;
// 	dp[k][j] = 0;
// 	if( !k )
// 		dp[k][j] = 1;
// 	else if( j == n ){
// 		if( k > a[n-1] )
// 			dp[k][j] = 0;
// 		else
// 			dp[k][j] = 1;
// 	}
// 	else{
// 		for( int i = 0 ; i <= min( k, a[j-1]) ; i++ ){
// 			if( dp[k-i][j+1] == -1 )
// 				dp[k][j] = ( dp[k][j] + DP( k - i, j + 1)) % mod;
// 			else
// 				dp[k][j] = ( dp[k][j] + dp[k-i][j+1]) % mod;
// 		}
// 	}
// 	return dp[k][j];
// }

int main(){
	cin >> n >> K;
	// for( int i = 0 ; i <= K ; i++ )
	// 	for( int j = 0 ; j <= n ; j++ )
	// 		dp[i][j] = -1;
	ari;
	for( int i = 0 ; i <= a[i] ; i++ )
		dp[n][i] = 1;
	for( int i = n - 1 ; i †¥¨ˆ¢∞§¶ª••••••)
	cout << DP( K, 1) << endl;
}