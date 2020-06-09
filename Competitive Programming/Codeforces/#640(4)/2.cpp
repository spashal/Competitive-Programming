#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, k;
int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> k;
		if( ( n >= k and k % 2 and n % 2 ) or ( n >=k and n % 2 == 0 and k % 2 == 0 ) ){
			cout << "YES" << endl;
			for( int i = 0; i < k - 1 ; i++ )
				cout << "1" << " ";
			cout << n - k + 1 << endl;
		}
		else if(  n % 2 == 0 and ( n >= 2*k and k % 2 ) ){
			cout << "YES" << endl;
			for( int i = 0 ; i < k - 1 ; i++ )
				cout << "2" << " ";
			cout << n - 2 * ( k - 1 ) << endl;
		}
		else
			cout << "NO" << endl;
	}
	return(0);
}