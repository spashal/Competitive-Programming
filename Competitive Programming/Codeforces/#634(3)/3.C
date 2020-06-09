#include <bits/stdc++.h>
using namespace std ;

int main(){
	int t , n , a[200005] , z , total , b[200005] , c[200005] ;
	vector< pair< int , int > > v ;
	cin >> t ;
	while( t-- ){
		cin >> n ;
		z = 0 ;
		for( int i = 1 ; i <= n ; i++ ){
			b[i] = 0 ;
			c[i] = 0 ;
		}
		for( int i = 1 ; i <= n ; i++ ){
			cin >> a[i] ;
			b[a[i]]++ ;
			c[a[i]] = 1 ;
		}
		for( int i = 1 ; i <= n ; i++ ){
			v.push_back( make_pair( b[i] , i ) ) ;
		}
		total = 0 ;
		for( int i = 1 ; i <= n ; i++ )
			if( c[i] )
				total++ ;
		sort( v.begin() , v.end() , greater< pair< int , int > > () ) ;
		// for( int i = 0 ; i < n ; i++ ){
		// 	if( v[i].first - 1 >= total ){
		// 		cout << total << endl ;
		// 		z = 1 ;
		// 		break ;
		// 	}
		// 	else if( i < n - 1 and v[i] > v[ i + 1 ] ){
		// 		if( v[i].first >= total - 1 ){
		// 			cout << total - 1 << endl ;
		// 			z = 1 ;
		// 			break ;
		// 		}
		// 	}
		// 	else if( i == n - 1 and v[ n - 1 ].first > total ){
		// 		cout << total << endl ;
		// 		z = 1 ;
		// 	}
		// 	else if( i == n - 1 and v[ n - 1 ].first == total ){
		// 		cout << total - 1 << endl ;
		// 		z = 1 ;
		// 	}

		// }
		// if( !z )
		// 	cout << v[n-1].first << endl ;
		if( v[0].first > total )
			cout << total << endl ;
		else if( v[0].first == total )
			cout << total - 1 << endl ;
		else
			cout << v[0].first << endl ;
		v.clear() ;
	}	
	return(0) ;
}