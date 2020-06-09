#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t , n ;
	cin >> t ;
	while( t-- ){
		cin >> n ;
		if( n % 2 ){
			cout << n / 2 << endl ;
		}
		else
			cout << ( n / 2 ) - 1 << endl ;
	}	
	return(0) ;
}