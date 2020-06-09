	#include <bits/stdc++.h>
	using namespace std;
	typedef long double ll;
	ll mpi = 3.14159265;
	ll t;
	int n;
	int main(){
	    ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
	    cin >> t;
		while( t-- > 0 ){
			cin >> n;
			if( n == 2 )
				cout << "1.0000000" << endl;
			else{
					ll ans = 0;
				if( (n-1)%2==0 ){
					ll angler = (ll)(mpi*(n-1))/(n);
					ll angle = angler/2;
					for( int i = 0 ; i < (n-1)/2 ; i++ ){
						ans += (ll)cos(angle);
						cout << ans << " ";
						angle = angler - (mpi/2) - ((mpi)/2 - angle);
					}
				}
				else{
					ll angler = (ll)(mpi*(n-1))/(n);
					ll angle = angler - (mpi/2);
					for( int i = 0 ; i < (n-1)/2 ; i++ ){
						ans += (ll)cos(angle);
						// cout << ans << " ";
						angle = angler - (mpi/2) - ((mpi)/2 - angle);
					}
					ans += 0.500000000;
				}
				ans *= 2;
				ans += 1;
				cout << fixed << setprecision(6) << ans << endl;
				// cout << fixed << setprecision(6) << 2 * ( ( ll)cos((ll)((n-1)*mpi)/( 2*n )) / ( 1 - cos( (ll)(mpi/n)))) << endl;
			}
			
		}
		return(0);
	}