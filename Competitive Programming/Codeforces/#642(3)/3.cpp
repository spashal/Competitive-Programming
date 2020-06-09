#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> n;
		ll ans = 0;
		for( ll i = 1 ; i <= n/2 ; i++ ){
			ans += i * ( ( 2 * i + 1 ) * ( 2 * i + 1 ) - ( 2 * i - 1 ) * ( 2 * i - 1 ) );
		}
		if( n == 1 )
			cout << "0" << endl;
		else
			cout << ans << endl;
	}
	return(0);
}