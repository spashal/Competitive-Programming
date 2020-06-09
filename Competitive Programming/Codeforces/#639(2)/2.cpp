#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t, n, ct;
	cin >> t;
	while( t-- ){
		cin >> n;
		int k = 0 ;
		ct = 0;
		for( int i = 1; i < n; i++ ){
			if( n < ( 1.5*i*(i+1) - i ) ){
				k = i;
				// cout << "k is " << k << endl;
				break;
			}
		}
		if( k == 0 ){
			cout << "0" << endl;
			break;
		}
		// cout << "heya" << endl;
		n -= 1.5*( k - 1 )*( k ) - k - 1;
		int i = k - 2;
		// cout << n << "is n" << endl;
		while( n > 0 and i > 0 ){
			n -=  1.5*i*(i+1) - i;
			ct++;
			i--;
			if( n < 0 )
				ct--;
		}
		cout << ct+1 << endl;
	}
	return(0);
}