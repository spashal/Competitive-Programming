#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, ans = 0, dp[100005], ct[100005];
vector< ll > a, v, ctr;

ll fun( ll i){
	if( dp[i] )
		return dp[i];
	if( i <= 1 or  v[i] != 2 + v[i-2] )
		dp[i] = v[i] * ct[v[i]];
	else if( v[ i - 2 ] + 2 == v[i] )
			dp[i] = fun( i - 2) + v[i] * ct[v[i]];
	if( i > 0 and v[i-1] + 1 == v[i] )
		dp[i] = max( dp[i], fun( i - 1 ));
	return dp[i];
}

int main(){
	cin >> n;
	for( int i = 0 ; i < n ; i++ ){
		ll k;
		cin >> k;
		ct[k]++;
		a.push_back(k);
	}
	vector< ll > :: iterator ip;
	sort( a.begin(), a.end());
	ip = std :: unique( a.begin(), a.end());
	a.resize( std :: distance( a.begin(), ip));
	for( int i = 0 ; i < a.size() ; i++ ){
		if( i == 0 and a[i+1] == a[i] + 1 )
			v.push_back(a[i]);
		else if( a[i] + 1 == a[i+1] or a[i-1] + 1 == a[i] ){
			v.push_back(a[i]);
			if( a[i] + 1 != a[i+1] and a[i-1] + 1 == a[i] )
				ctr.push_back(v.end() - v.begin() - 1);
		}
		else if( i == a.size() - 1 and i > 0 and a[i-1] + 1 == a[i] ){
			v.push_back(a[i]);
			ctr.push_back( v.end() - v.begin() - 1);
		} 
		else
			ans += ct[a[i]] * a[i];
	}
	for( int i = 0 ; i < ctr.size() ; i++ )
		ans += fun(ctr[i]);
	cout << ans << endl;
	return(0);
}