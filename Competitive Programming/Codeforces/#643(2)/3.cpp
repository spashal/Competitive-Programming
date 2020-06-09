#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, a, b, c, d;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
		ll ans = 0;
		cin >> a >> b >> c >> d;
		for( int i = c ; i <= d ; i++ ){
			ll delta = b + c - i;
			if( delta > 0 ){
				if( i < a + b )
					ans += (b-a+1)*(c-b+1);
				else if( delta <= (b-a+1) and delta <= (c-b+1) )
					ans += ( delta * ( delta + 1 )) / 2;
				else if( delta > min( b-a+1, c-b+1))
					ans += (min( b-a+1, c-b+1)*(min( b-a+1, c-b+1) + 1))/2;
				// cout << ans << " ";
			}
		}
		cout << ans << endl;
	return(0);
}