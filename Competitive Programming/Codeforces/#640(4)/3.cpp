#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, k;
int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> k;
		if( k % ( n - 1 ) )
			cout << (k/(n-1))*n+k%(n-1) << endl;
		else
			cout << ( k / ( n - 1 ) ) * n - 1 << endl;
	}
	return(0);
}