#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	long long int a , nr , ng , nb , x , y , z , b , t , maxa ;
	set< int , greater< int > > :: iterator itr ;
	set< int , greater< int > > v1 ; 
	set< int , greater< int > > v2 ; 
	set< int , greater< int > > v3 ;
	cin >> t ;
	while( t-- ){
		cin >> nr >> ng >> nb ;
		for( int i = 0 ; i < nr ; i++ ){
			cin >> a ;
			v1.insert(a) ;
		}
		for( int i = 0 ; i < ng ; i++ ){
			cin >> a ;
			v2.insert(a) ;
		}
		for( int i = 0 ; i < nb ; i++ ){
			cin >> a ;
			v3.insert(a) ;
		}
		maxa = 2 * 1e18 + 2 ;
		for( itr = v1.begin() ; itr != v1.end() ; itr++ ){
			y = *( v2.lower_bound(*itr) ) ;
			z = *( v3.lower_bound(*itr) ) ;
			b = ( ll )( *itr - y ) * ( *itr - y ) + ( ll )( *itr - z ) * ( *itr - z ) + ( ll )( y - z ) * ( y - z ) ;
			cout << maxa << " " ;
			if( maxa > b )
				maxa = b ;
		}
		for( itr = v2.begin() ; itr != v2.end() ; itr++ ){
			x = *( v1.lower_bound(*itr) ) ;
			z = *( v3.lower_bound(*itr) ) ;
			b = ( ll )( *itr - x ) * ( *itr - x ) + ( ll )( *itr - z ) * ( *itr - z ) + ( ll )( x - z ) * ( x - z ) ;
			cout << maxa << " " ;
			if( maxa > b )
				maxa = b ;
		}
		for( itr = v3.begin() ; itr != v3.end() ; itr++ ){
			x = *( v1.lower_bound(*itr) ) ;
			y = *( v2.lower_bound(*itr) ) ;
			b = ( ll )( *itr - x ) * ( *itr - x ) + ( ll )( *itr - y ) * ( *itr - y ) + ( ll )( x - y ) * ( x - y ) ;
			cout << maxa << " " ;
			if( maxa > b )
				maxa = b ;
		}
		cout << endl ;
		cout << maxa << endl ;
		v1.clear() ;
		v2.clear() ;
		v3.clear() ;
	} 
}