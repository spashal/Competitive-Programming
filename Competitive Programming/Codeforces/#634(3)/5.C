#include <bits/stdc++.h>
using namespace std ;

int main(){
	int t , n ;
	vector< pair< pair< int , int > , pair< int , int > > v[2005][2] ; 
	cin >> t ;
	while( t-- ){
		cin >> n ;
		for( int i = 0 ; i < n ; i++ )
			cin >> a[i] ;
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < n ; j++ ){
				if( v[i][0].first.first == a[j] ){
					v[i][0].first.first++ ;
				}
				if( v[i][1].first.first == a[j] ){
					v[i][1].first.first++ ;
				}
				else if( v[i].second.first == 0 ){

				}
			}
	}
	return(0) ;
}