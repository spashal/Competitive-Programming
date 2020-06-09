#include <bits/stdc++.h>
using namespace std;
typedef long double ll;
ll t, n, h, c, T;

int main(){
	cin >> t;
	while( t-- ){
		cin >> h >> c >> T;
		if( T >= h )
			cout << "1" << endl;
		// else if( T > )
		else if( T <= ( c + h )/ 2 )
			cout << "2" << endl;
		else{
			ll g = ( T - h )/( (ll)( c + h ) / 2 - T );
			g = (long long int)g;
			// cout << g << endl;
			if( (long long int)g % 2 == 1 ){
				ll a1 = T - ( c * ( g + 1 ) / 2 + h * ( g + 3 ) / 2 )/(g+2);
				ll a2 = T - ( c * ( g - 1 ) / 2 + h * ( g + 1 ) / 2 )/(g);
				ll a3 = T - ( c * ( g + 3 ) / 2 + h * ( g + 5 ) / 2 )/(g+4);
				if( a1 < 0 )
					a1 *= -1;
				if( a2 < 0 )
					a2 *= -1;
				if( a3 < 0 )
					a3 *= -1;
				if( a2 <= a1 and a2 <= a3 )
					cout << g << endl;
				else if( a1 <= a2 and a1 <= a3 )
					cout << g + 2 << endl;
				else
					cout << g + 4 << endl;
			}
			else{
				ll a1 = T - ( c * g / 2 + h * ( g + 2 )/ 2)/(g+1);
				ll a2 = T - ( c * ( g + 2 ) / 2 + h * ( g + 4 )/ 2)/(g+3);
				if( a1 < 0 )
					a1 *= -1;
				if( a2 < 0 )
					a2 *= -1;
				if( a1 <= a2 )
					cout << g + 1 << endl;
				else
					cout << g + 3 << endl;
			}
		}
	}
	return(0);
}