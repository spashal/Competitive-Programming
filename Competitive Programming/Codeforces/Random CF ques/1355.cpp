#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll A, B, C, D;

ll f( ll c, ll z, ll a, ll b){
	ll ans = 0;
	if( a + b <= z ){
		ll k = min( b - a + 1, z - a - b + 1);
		ans += ( k * ( k + 1 )) / 2;
		ans += ( c - ( z - a)) * ( b - a + 1);
	}
	else if( b + c > z )
		ans = ( b - a + 1 ) * ( c - b + 1 );
	return ans;
}

ll f1( ll a, ll b, ll c, ll z){
	ll ans = 0;
	if( a + b <= z ){
		ll k = min( c - b + 1, z - a - b + 1);
		ans += ( k * ( k + 1 )) / 2;
		ans += ( b - ( z - b)) * ( c - a + 1);
	}
	else if( b + c > z )
		ans = ( b - a + 1 ) * ( c - b + 1 );
	return ans;	
}

int main(){
	cin >> A >> B >> C >> D;
	ll ans = 0;
	for( int i = C ; i <= D ; i++ ){
		if( ( B - A ) < ( C - B ))
			ans += f( C, i, A, B);
		else
			ans += f1( A, B, C, i);
		cout << ans << " ";
	}
	cout << endl << ans << endl;
	return(0);
}