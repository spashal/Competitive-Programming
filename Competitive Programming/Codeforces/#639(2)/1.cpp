#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t, n, m;
	cin >> t;
	while( t-- ){
		cin >> n >> m;
		if( n == 1 or m == 1 or ( n == 2 and m == 2 ) )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return(0);
}