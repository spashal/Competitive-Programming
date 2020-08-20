#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[505], b[505], t, n;
#define ari for( int i = 0 ; i < n ; i++ ) cin >> a[i];
#define bri for( int i = 0 ; i < n ; i++ ) cin >> b[i];

int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		ari;bri;
		int z = 0;
		if( n % 2 == 1 ){
			if( a[n/2] != b[n/2] )
				z = 1;
			for( int i = 0 ; i < n / 2 ; i++ ){
				if( a[i] == b[i] and a[n-i-1] != b[n-i-1] )
					z = 1;
				else if( a[i] == b[n-i-1] and a[n-i-1] != b[i] )
					z = 1;
				else if( ( a[i] != b[n-i-1] and a[i] != b[i] ) or ( a[n-i-1] != b[i] and a[n-i-1] != b[n-i-1] ) )
					z = 1;
			}
		}
		else{
			for( int i = 0 ; i < n / 2 ; i++ ){
				if( a[i] == b[i] and a[n-i-1] != b[n-i-1] )
					z = 1;
				else if( a[i] == b[n-i-1] and a[n-i-1] != b[i] )
					z = 1;
				else if( ( a[i] != b[n-i-1] and a[i] != b[i] ) or ( a[n-i-1] != b[i] and a[n-i-1] != b[n-i-1] ) )
					z = 1;
			}			
		}
		if( z )
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
	return(0);
}