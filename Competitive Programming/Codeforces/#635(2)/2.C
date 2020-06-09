#include <bits/stdc++.h>
using namespace std ;
int x , n , m , t , z ;

int fun(){
	if( x >= 20 and n ){
		n-- ;
		return ( x/2 + 10 ) ;
	}
	else if( x < 20 and m ){
		m-- ;
		return ( x - 10 ) ;
	}
	else if( n ){
		n-- ;
		return ( x/2 + 10 ) ;
	}
	m-- ;
	return x - 10 ;
}

int main(){
	cin >> t ;
	while( t-- ){
		z = 0 ;
		cin >> x >> n >> m ;
		while( n or m ){
			x = fun() ;
			if( x <= 0 ){
				z = 1 ;
				break ;
			}
		}
		if( z )
			cout << "YES" << endl ;
		else
			cout << "NO" << endl ;
	}
	return(0) ;
}