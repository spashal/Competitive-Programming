#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n;
vector< int > as(n+1);
vector< int > dp[100005];

void fun( ll a){
	if( a == n ){
		dp[n].push_back(0);
		dp[n].push_back(-31);
		return;
	}
	if( dp[a+1][0] == -6000006 )
		fun(a+1);
	if( dp[a+1][1] < 0 ){
		dp[a][0] = 0;
		dp[a][1] = as[a];
	}
	else if( dp[a+1][1] > as[a] ){
		dp[a][0] = dp[a+1][0] + as[a];
		dp[a][1] = dp[a+1][1];
	}
	else if( as[a] > dp[a+1][0] + dp[a+1][1] ){
		dp[a][0] = dp[a+1][0] + dp[a+1][1];
		dp[a][1] = as[a];
	}
	else{
		dp[a][0] = 0;
		dp[a][1] = as[a];
	}
}

int main(){
	cin >> n ;
	for( int i = 0 ; i < n ; i++ ){
		cin >> as[i];
		dp[i].push_back(-6000006);
	}
	fun(0);
	cout << dp[0][0] << endl;	
	return(0);
}