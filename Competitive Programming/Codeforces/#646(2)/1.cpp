#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n;

int main(){
	cin >> t;
	while( t-- ){
		ll a, x, odd = 0, even = 0;
		cin >> n >> x;
		for( int i = 0 ; i < n ; i++ ){
			cin >> a;
			if( a % 2 == 1 )
				odd++;
			else
				even++;
		}
		if( ( odd > 0 and x < n and ( x % 2 == 1 or ( x % 2 == 0 and even > 0 ))) or ( x == n and ( odd % 2 == 1) ) )
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return(0);
}