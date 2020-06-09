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
		// if( n == 2 )
		// 	cout << "1.0000000" << endl;
		// else{
		ll ans = 0;
		ll angler = (ll)((ll)mpi*(n-1))/(n);
		cout << angler << "*" << endl;
		ll angle = angler/2;
		for( int i = 0 ; i < (n-1)/2 ; i++ ){
			ans += (ll)sin(angle);
			cout << ans << " ";
			angle = angler - (mpi/2) - ((mpi)/2 - angle);
		}
		ans = 0.70710678 + (ll)ans/0.70710678;
		// ans += 1;	
		cout << fixed << setprecision(6) << ans << endl;
	}
	return(0);
}