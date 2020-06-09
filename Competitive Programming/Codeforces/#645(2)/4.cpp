#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, d[200005], x;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> x;
	ll first = 0, here;
	ll mama = 0;		
	for( int i = 0 ; i < n ; i++ ){
		cin >> d[i];
		if( first < d[i] ){
			first = d[i];
			here = i;
		}
	}
	ll hey = x;
	// cout << hey << endl;
	// cout << x << " " << here << endl;
	for( int i = 0 ; i < n ; i++ ){
		ll ans = 0;
		here = i;
		while( x > 0 ){
			if( d[here] <= x ){
				ans += (d[here]*(d[here]+1))/2;
				x -= d[here];
				here--;
			// cout << "whoa" << endl;
				if( here < 0 )
					here = n - 1;
			}
			else{
				ans += (d[here]*(d[here]+1))/2 - ((d[here]-x)*(d[here]-x+1))/2;
				x = 0;
			// cout << "haha" << endl;
			}
			// cout << "hi" << endl;
		}
		// cout << "end" << endl;
		x = hey;
		mama = max( ans, mama);
	}
	cout << mama << endl;
	return(0);
}