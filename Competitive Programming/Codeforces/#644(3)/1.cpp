#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, a , b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
	while( t-- ){
		cin >> a >> b;
		if( a < b ){
			if( ( 2 * a ) >= b )
				cout << 4 * a * a << endl;
			else
				cout << b * b << endl;
		}
		else{
			if( ( 2 * b ) >= a )
				cout << 4 * b * b << endl;
			else
				cout << a * a << endl;
		}
	}
	return(0);
}