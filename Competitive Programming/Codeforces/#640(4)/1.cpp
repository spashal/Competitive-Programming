#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n;

int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		ll i = 0;
		ll k;
		ll j = 0 ;
		ll s = n;
		for( int i = 1 ; n > 0 ; i++ ){
			if( n % 10 )
				j++;
			n /= 10;
		}
		n = s;
		cout << j << endl;
		while( n > 0 ){
			if( n % 10 )
			cout << n % 10;
			k = 0;
			if( n % 10 > 0 ){
				while( k++ < i )
				cout << "0"; 
			cout << " ";
			}
			n /= 10;
			
			i++;
		}
		cout << endl;
	}
	return(0);
}