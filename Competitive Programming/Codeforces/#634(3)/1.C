#include <bits/stdc++.h>
using namespace std ;
int a[10][10] ;
void fun( int c , int b ){
	if( a[c][b] == 9 )
		a[c][b] = 1 ;
	else
		a[c][b] = 9 ;
}

int main(){
	int t ;
	char s[11] ;
	cin >> t ;
	while( t-- ){
		for( int i = 0 ; i < 9 ; i++ ){
			cin >> s ;
			for( int j = 0 ; j < 9 ; j++ )
				a[i][j] = s[j] - 48 ;
		}
			
		fun(0,0) ;
		fun(3,1) ;
		fun(6,2) ;
		fun(1,3) ;
		fun(4,4) ;
		fun(7,5) ;
		fun(2,6) ;
		fun(5,7) ;
		fun(8,8) ;
		for( int i = 0 ; i < 9 ; i++ ){
			for( int j = 0 ; j < 9 ; j++ )
				cout << a[i][j] ;
			cout << endl ;
		}
	}	
	return(0) ;
}