#include <bits/stdc++.h>
using namespace std ;

int main(){
	int t , n , a , b ;
	char s ;
	cin >> t ;
	while( t-- ){
		cin >> n >> a >> b ;
		for( int i = 0 ; i < n ; i++ ){
			s = 97 + ( i % b ) ;
			cout << s ;
		}
		cout << endl ;
	}
	return(0) ;
}